## => file_name: main_v1.rb
## => describe: the main file that control the flow of the application
## => author: jinguodong
## => time: 2014-1-3
## => some changes from main.rb
	# rebuild the main control flow
## => usage:
	# main = MainScan.new(sip_stack_version, test_path, test_sip_path)
	# main.file_analyze # => model the project of the test_sip_path
	# main.source_sip_stack(file_name, function_name) # => source the project by file_name and function_name.
	# => main.source_sip_stack return the headers of sip.
	# main.sip_generate(_sip_header="", _sip_type="")
	# => _sip_header: is the SIP header of the malformed sip packet that is going to be generated
	# => _sip_type: is the type of the SIP header of the malformed sip packet that is going to be generated
## => example:
	# sip_stack_version = "opensips_1_10"
	# test_path = `pwd`.chop! + "/#{sip_stack_version}"
	# test_sip_path = test_path+"/parser"
	# main = MainScan.new(sip_stack_version, test_path, test_sip_path)
	# file_name = test_sip_path+"/parse_to.c"
	# function_name = "parse_to_param"
	# p main.source_sip_stack(file_name, function_name)
## => edit 
	# add vulnerability_function.rb to deal with the vulnerability function
	# To get the format value of the vulnerability function:
	# VulnerabilityFunction.new().get_value_by_funcname('memcpy')
	# To get the file name and function name of the vulnerability function:
	# VulnerabilityFunction.new().get_info_of_funcname('memcpy')
	
require "./source_sip_stack"
require "./file_analyze"
require "./sip_mysql_cfg"
require "/opt/SipGenerator_ruby/malfSipMsgGen.rb"
require "./vulnerability_function.rb"
require "./format_sip_generate.rb"
require "yaml"
require "./client_sip_attack_value_test.rb"

class MainScan
	attr_accessor :test_client
	def initialize(_sip_stack_version="opensips_1_10", _test_path="", _test_sip_path="")
		@sip_stack_version = _sip_stack_version
		@test_path =_test_path
		@test_sip_path = _test_sip_path
		@source_sip_stack = SourceSipStack.new(@sip_stack_version)
		@vulnerability = VulnerabilityFunction.new()
		@gen_enum_res = []
		@gen_enum_tem = []
		@iiii = 0
		@iii_flag = 0
		@file_path = './format_sips/'
		# set ClientSipTest init param
		uip = "10.109.247.207"
		uport = "5067"
		server_Uri = "10.109.247.207"
		rip = "10.109.247.207"
		rport = "5060"
		from_user = 'alice'
		to_user = 'alice'
		@test_client =  ClientSipTest.new(uip, uport, rip, rport, server_Uri, from_user, to_user)
		@sip_gen = FormatSipGenerate.new
		@test_gen_cnt = 0
	end

	# To get the format value of the vulnerability function:
	def get_value_by_funcname(_func_name)
		@vulnerability.get_value_by_funcname(_func_name)
	end
	# To get the file name and function name of the vulnerability function:
	def get_info_of_funcname(_func_name)
		@vulnerability.get_info_of_funcname(_func_name)
	end

	def source_sip_stack(_file="", _function="", _other_info="")
		# test = SourceSipStack.new(sip_stack_version, "#{test_sip_path}/parse_to.c", "test", "strcpy")
		
		@source_sip_stack.set_other_info(_other_info)
		@source_sip_stack.source_sip_file("#{_file}", "#{_function}")#{test_sip_path}/parse_to.c
		@source_sip_stack.get_sip_header_from_source_result
	end
	def source_sip_stack_clear
		@source_sip_stack.clear
	end
	def source_result
		@source_sip_stack.get_source_result
	end

	def file_analyze
		# test on 2013_10_16_14_40 by jinguodong
		test = FileAnalyze.new(@sip_stack_version)
		stack_files = StaticFunction.get_files(@test_sip_path)
		stack_files.each do |f|
			test.set_file(f)
			test.file_cflow_v1
		end
	end
	def sip_generate(_sip_header="", _sip_type="")
		#define a MalfSipMsgGen object
		if _sip_header=="" && _sip_type==""
			# puts "System may generate all Malformed SIP packet, Yes or No?"
			# _user_input = gets()
			# if _user_input =~ /no/i
			# 	return
			# end
			return
		end
		sMsgGen=MalfSipMsgGen.new("REGISTER5")
		orgMsg=sMsgGen.getSipMsgFromFile("/opt/SipGenerator_ruby/template/REGISTER.txt")
		if _sip_header!="" && _sip_type==""
			sMsgGen.generateAllMalformedMsgbySipMsgElement(orgMsg,_sip_header)
		elsif _sip_header!="" && _sip_type!=""
			raise "#{__FILE__}:#{__LINE__}: param error"
			#sMsgGen.generateMalformedMsg(orgMsg,_sip_header,_sip_type)
		end
		#sMsgGen.generateAllMalformedMsg(orgMsg)
		# sMsgGen.generateAllMalformedMsgbySipMsgElement(orgMsg,"SIP-Content-Length")
	end
	def get_sip_template
		sMsgGen=MalfSipMsgGen.new("REGISTER5")
		orgMsg=sMsgGen.getSipMsgFromFile("/opt/SipGenerator_ruby/template/REGISTER.txt")
	end
	# sent the sip to tested nest
	def get_sip_from_pre_v1(pre_format_sip='')
		format_sip = @test_client.test_preformat_sip_once(pre_format_sip)
		# get final perform of the format sip.
		format_sip
	end
	# test format sip for once.
	def test_format_sip_v1(format_sip='')
		@test_client.test_format_sip_once_v1(format_sip)
	end
	# start sip server
	def start_sip_server
		`/home/jinguodong/open_project/opensips_1_10/opensips >/tmp/mysips.log 2>/dev/null &`
	end
	# kill sip server
	def kill_sip_server
		`kill -9 $(ps -ef | grep opensips | awk '{print $2}' )`
	end
	# start a test, set up the test env
	# after set up the test and end a test, call kill_sip_server will be suggested.
	# 
	def set_up_test_env
		`ruby expect_test_v1.rb`
	end
	def deal_result(input)
		@test_client.deal_test_result(input)
	end
	def do_genetic(gened_crow_1=[])
		cnt_hash = {}
		# p gened_crow_1.size
		gened_crow_1.each do |gen|
			# p gen['sip_info'][0]['sip_header_v1']
			# p cnt_hash[gen['sip_info'][0]['sip_header_v1']]
			if cnt_hash[gen['sip_info'][0]['sip_header_v1']] != nil
				cnt_hash[gen['sip_info'][0]['sip_header_v1']] = cnt_hash[gen['sip_info'][0]['sip_header_v1']]+1
			else
				cnt_hash[gen['sip_info'][0]['sip_header_v1']] = 1
			end
		end
		p cnt_hash
		if cnt_hash.size<2
			return []
		end
		gen_dp=2;
		while gen_dp <= cnt_hash.size do 
			gen_enum(gened_crow_1, 0, gen_dp, 0)

			puts "gen ok! total num : #{@gen_enum_res[gen_dp].size}"
			cnt_res = 0;
			while(cnt_res<= @gen_enum_res[gen_dp].size) do
				cnt_res = cnt_res + 10000
				if(cnt_res >= @gen_enum_res[gen_dp].size)
					open(@file_path+"gen_enum_#{gen_dp}_#{cnt_res-10000}_#{@gen_enum_res[gen_dp].size}.yaml", 'w') { |f| YAML.dump(@gen_enum_res[gen_dp][(cnt_res-10000)...(@gen_enum_res[gen_dp].size)], f) }	
				else
					open(@file_path+"gen_enum_#{gen_dp}_#{cnt_res-10000}_#{cnt_res}.yaml", 'w') { |f| YAML.dump(@gen_enum_res[gen_dp][(cnt_res-10000)...(cnt_res)], f) }
				end
			end
			# open(@file_path+"gen_enum_#{gen_dp}.yaml", 'w') { |f| YAML.dump(@gen_enum_res[gen_dp], f) }			
			puts "gen_enum_#{gen_dp} : size : #{@gen_enum_res[gen_dp].size}"
			gen_dp = gen_dp+1
		end
	end
	def gen_enum(gened_crow_1=[], cur, n, p)
		# enum
		if cur == n
			@iiii = @iiii+1
			# puts "gened #{@iiii}"
			STDOUT.flush
			_tem=nil
			@gen_enum_tem.each do |tem_sip|
				if _tem == nil
					eval "_tem = #{tem_sip.to_s}"
				else
					tem_sip['sip_info'].each do |tem_sip_header|
						_tem["sip_info"] << tem_sip_header	
					end
				end
			end
			_tem['expect_value'] = 0
			_tem['fact_value'] = 0
			_tem['sip_info'].each do |tem_header|
				_tem['expect_value'] = _tem['expect_value'] + tem_header['expect_value']
				_tem['fact_value'] = _tem['fact_value'] + tem_header['fact_value']
			end
			if @gen_enum_res[n]==nil
				@gen_enum_res[n] = []
			end
			@gen_enum_res[n] << _tem
			# puts _tem['sip_info'].size
			# puts @gen_enum_res[n].size
			# STDOUT.flush
			
			return 
		end

		gened_crow_1.each_index do |i|
			if i<p
				next
			end
			flag = 0
			if gened_crow_1[i]["gened_#{n}"]=='true'
				# puts "true : i: #{i}"
			end
			if gened_crow_1[i]["gened_#{n}"]!='true'
				@gen_enum_tem.each do |gened_sip|
					# puts gened_sip['sip_info'][0]['sip_header_v1']
					# puts gened_crow_1[i]['sip_info'][0]['sip_header_v1']
					# STDOUT.flush
					if gened_sip['sip_info'][0]['sip_header_v1'] == gened_crow_1[i]['sip_info'][0]['sip_header_v1']
						flag = 1
					end
				end

				if flag == 1
					@iii_flag = @iii_flag+1
					# puts "next : cur: #{cur}: i: #{i} : #{@iii_flag}"
					# puts gened_crow_1[i]['sip_info'][0]['sip_header_v1']
					next
				end

				gened_crow_1[i]["gened_#{n}"]='true'
				@gen_enum_tem << gened_crow_1[i]
				if cur==3
					# puts @gen_enum_tem.size
				end

				# puts "i:#{i}"
				gen_enum(gened_crow_1, cur+1, n, i)
				@gen_enum_tem.pop
				gened_crow_1[i]["gened_#{n}"]='false'
			end
		end
		return @gen_enum_res[n]
	end
	def test_gen(sip_infos)
		sip_infos.each do |input|
			format_sip = @sip_gen.get_premessage_from_template(input['sip_info'], get_sip_template)

			# start the service of opensips
			set_up_test_env
			sleep(1)
			# test format sip for once.
			format_sip_to_send = get_sip_from_pre_v1(format_sip)
			test_format_sip_v1(format_sip_to_send)

			# kill sip server, after the end of a test.
			sleep(1.5)
			kill_sip_server
			@test_gen_cnt = @test_gen_cnt + 1
			puts "test : #{@test_gen_cnt}"
			sleep(0.5)

			# here, deal with the result of this test.
			fact_value = deal_result(input)

			# @sip_gen.write_to_file(format_sip, "#{file_path}#{i}")
		end
	end
end

sip_stack_version = "opensips_1_10"
test_path = `pwd`.chop! + "/#{sip_stack_version}"
test_sip_path = test_path+"/parser"
# test_sip_path = test_path
main = MainScan.new(sip_stack_version, test_path, test_sip_path)

# read the test gened of first crow from 'gened_crow_1.yaml'
gened_crow_1 = open('gened_crow_1.yaml', 'r') { |f| YAML.load(f) }

t_cnt = 0
f_cnt = 0
v_cnt = 0
c_cnt = 0
# puts gened_crow_1
# p gened_crow_1.size
cnt_hash = {}
gened_crow_1.each do |gen|
	if cnt_hash[gen['sip_info'][0]['sip_header_v1']] != nil
		cnt_hash[gen['sip_info'][0]['sip_header_v1']] = cnt_hash[gen['sip_info'][0]['sip_header_v1']]+1
	else
		cnt_hash[gen['sip_info'][0]['sip_header_v1']] = 1
	end
	case gen['sip_info'][0]['sip_header_v1']
	when 'To'
		t_cnt = t_cnt+1
	when 'From'
		f_cnt = f_cnt+1
	when 'Via'
		v_cnt = v_cnt+1
	when 'Contact'
		c_cnt = c_cnt+1
	end
end
p cnt_hash.size
puts "#{t_cnt}:#{f_cnt}:#{v_cnt}:#{c_cnt}"
STDOUT.flush

file_path = './format_sips/'
format_sips_dir = []
Dir.foreach("#{file_path}") do |x|
	if x =~ /gen_enum_\d*_\d*_\d*_tested[.]yaml/
		puts x
		format_sips_dir << x
	end
end

puts "format sip dir"

format_sips_dir.sort! do |x, y|
	y <=> x
end
puts format_sips_dir


result_tested_sips = []
format_sips_dir.each do |file_name|
	hash_gen = open(file_path+"#{file_name}", 'r') { |f| YAML.load(f) }
	# puts hash_gen[x]
	hash_gen.each do |input|
		if input['expect_value'] != input['fact_value']
			next
		end
		is_dup = 0
		no_dup_cnt = 0
		input['sip_info'].each do |sip|
			_sip_header = sip['sip_header']
			_value_id = sip['value_id']
			_v_func = sip['v_func']

			gened_crow_1.each do |crow1_sip|
				crow_sip_header = crow1_sip['sip_info'][0]['sip_header']
				crow_value_id = crow1_sip['sip_info'][0]['value_id']
				crow_v_func = crow1_sip['sip_info'][0]['v_func']
				if _sip_header == crow_sip_header && _value_id == crow_value_id && _v_func == crow_v_func
					if crow1_sip['result_tested'] != nil
						is_dup = 1
						break
					end
					no_dup_cnt = no_dup_cnt + 1
				end
			end
			if is_dup == 1
				break
			end
		end
		if is_dup == 0 && no_dup_cnt == input['sip_info'].size
			input['sip_info'].each do |sip|
				_sip_header = sip['sip_header']
				_value_id = sip['value_id']
				_v_func = sip['v_func']

				gened_crow_1.each do |crow1_sip|
					crow_sip_header = crow1_sip['sip_info'][0]['sip_header']
					crow_value_id = crow1_sip['sip_info'][0]['value_id']
					crow_v_func = crow1_sip['sip_info'][0]['v_func']
					if _sip_header == crow_sip_header && _value_id == crow_value_id && _v_func == crow_v_func
						crow1_sip['result_tested'] = 'true'
					end
				end
			end
			result_tested_sips << input
		end
	end
end

puts "result_tested_sips:#{result_tested_sips.size}"
puts result_tested_sips


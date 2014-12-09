## => file_name: main_v1.rb
## => describe: the main file that contral the flow of the application
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
	def do_genetic_v2(gened_crow_1=[])
	# genetic sips with gened_crow_1 by second-best solution.
		gen_map = {}
		gened_crow_1.each do |gen|
			sip_header_key = gen['sip_info'][0]['sip_header_v1']
			if gen_map[sip_header_key] == nil
				gen_map[sip_header_key] = []
			end
			gen_map[sip_header_key] << gen
		end
		max_len = 0
		gen_map.each do |k, v|
			if max_len < v.size
				max_len = v.size
			end
		end
		if max_len < 1
			return nil
		end
		gen_res = []
		ii = 0
		while ii < max_len do
			_tem = nil
			gen_map.each do |k, v|
				len = v.size
				if ii<len
					if _tem == nil
						eval "_tem = #{v[ii].to_s}"
					else
						_tem['sip_info'] << v[ii]['sip_info'][0]
						_tem['expect_value'] = _tem['expect_value'] + v[ii]['expect_value']
						_tem['fact_value'] = _tem['fact_value'] + v[ii]['fact_value']
						
					end
				end
				# puts 'iii'
				# puts _tem
			end
			gen_res[ii] = _tem
			ii = ii + 1
		end
		puts 'gen_res'
		puts gen_res
		gen_res
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

# analyze the test_sip_path, model the sip stack;
# main.file_analyze	
# puts "file_analyze complete"

# get the file and func of vulnerability function setted by other_info
other_info = "malloc"
file_func_array = main.get_info_of_funcname(other_info)
puts "file_name"=>"/home/jinguodong/workspace/sip_stack_analyze_dir/                      vulnerability-function: malloc"
puts file_func_array

# middle_result store the middle result of control flow
# performance:
# [{'sip_header'=>, 'v_func'=>, 'file_name'=>, 'func_name'=>}, ...]
middle_result = []
file_func_array.each do |file_func|
	file_name = file_func["file_name"]
	function_name = file_func["function_name"]
	main.source_sip_stack_clear
	sip_tmp_result = main.source_sip_stack(file_name, function_name, other_info)
	# puts file_func["file_name"]
	# puts file_func["function_name"]
	# p sip_tmp_result
	# p sip_tmp_result.empty?
	if !sip_tmp_result.empty?
		sip_tmp_result.each do |key, value|
			# p key
			middle_result << {'sip_header'=>key, 'v_func'=>other_info, 'file_name'=>file_func['file_name'], 'func_name'=>file_func['function_name']}
 			# middle_result << {'sip_header'=>key, 'v_func'=>other_info, 'file_name'=>'**', 'func_name'=>file_func['function_name']}
		end
	end
end

middle_result.uniq!
puts middle_result
# puts middle_result.size

# deal with middle_result, get the preform of first crow, as follows:
# [{:sip_info=>[{:sip_header, :value, :v_func, :aims=>[{:file, :func},..], :expect_value, :fact_value}, ...], :expect_value, :fact_value}, ...]
# 0...i 	[0, i-1]
# first_crow_pre the preform of first crow of genetic.
first_crow_pre=[]
for ele1 in (0...middle_result.size)
	# puts middle_result[ele1]
	tem_result = {}
	if middle_result[ele1]['vis'] != 'true'
		middle_result[ele1]['vis'] = 'true'
		tem_result = { 
			'sip_info'=>[
				{
					'sip_header'=>middle_result[ele1]['sip_header'],
					'value'=>'',
					'v_func'=>middle_result[ele1]['v_func'],
					'aims'=>[
						{
							'file'=>middle_result[ele1]['file_name'],
							'func'=>middle_result[ele1]['func_name']
						}
					],
					'expect_value'=>1,
					'fact_value'=>-1,
				}
			],
			'expect_value'=>1,
			'fact_value'=>-1
		}
		for ele2 in (0...middle_result.size)
			if middle_result[ele2]['vis']!='true' && 
				middle_result[ele2]['sip_header']==middle_result[ele1]['sip_header'] && 
				middle_result[ele2]['v_func']==middle_result[ele1]['v_func'] &&	
				middle_result[ele2]['value']==middle_result[ele1]['value']

				middle_result[ele2]['vis']='true'
				tem_result['sip_info'][0]['aims']<<{'file'=>middle_result[ele2]['file_name'], 'func'=>middle_result[ele2]['func_name']}
				tem_result['sip_info'][0]['expect_value']=tem_result['sip_info'][0]['expect_value']+1
				tem_result['expect_value']=tem_result['expect_value']+1
			end
		end
		# puts tem_result
		first_crow_pre<<tem_result
	end
end
# puts 'first_crow_pre:'
# puts first_crow_pre


# get related SIP header param array header
# $SIP_MYSQL(init in sip_mysql_cfg.rb) store the relation of sip_header and sip params.
# get first_crow_pre1 with first_crow_pre and $SIP_MYSQL, perform as follows:
# [{:sip_info=>[{:sip_param, :value, :v_func, :aims=>[{:file, :func},..], :expect_value, :fact_value}, ...], :expect_value, :fact_value}, ...]
first_crow_pre1 = []
# first_crow_pre1
first_crow_pre.each do |ele|
	tem = {}
	tem = ele.dup
	k = tem['sip_info'][0]['sip_header']
	puts "SIP_header: #{k}"
	puts $SIP_MYSQL[k]
	$SIP_MYSQL[k].each do |_header|
		tem['sip_info'][0]['sip_header'] = _header
		tem['sip_info'][0]['sip_header_v1'] = k
		# puts tem
		tem1 = {}
		tem1 = tem.dup
		eval "first_crow_pre1 << #{tem1.to_s}"
		# main.sip_generate(_header)
	end
end
# puts "first_crow_pre1:"
# puts first_crow_pre1

# get the format value of the vulnerability function:
format_value_array = main.get_value_by_funcname(other_info)
puts "format_value_array: #{other_info}"
puts format_value_array

# first crow
# [{:sip_header=>"", :value=>"", :value_class=>30}, ..]
# Change to 
# [{:sip_info=>[{:sip_header, :value, :value_id, :value_class, :v_func, :aims=>[{:file, :func},..], :expect_value, :infect_value}, ...], 
# :expect_value, :infect_value}, ...]
# edit at 2014-1-3 by jinguodong
# get first_crow finaly.
first_crow = []
first_crow_pre1.each do |ele1|
	tem = ele1
	format_value_array = main.get_value_by_funcname(tem['sip_info'][0]['v_func'])
	# puts format_value_array
	format_value_array.each do |value|
		tem['sip_info'][0]['value'] = value['value']
		tem['sip_info'][0]['value_id'] = value['value_id']
		tem['sip_info'][0]['value_class'] = value['value_class']
		# puts tem
		eval "first_crow << #{tem.to_s}"
	end
end
puts "first_crow"
puts first_crow

### start the test of first_crow
# # start the service of opensips
# main.set_up_test_env

# # generate the first crow with first_crow array.
# sip_res = FormatSipGenerate.new
# # format_sip = ''
file_path = './format_sips/'
# `rm -f ./format_sips/*`
# i=0
# first_crow.each do |input|
# 	format_sip = sip_res.get_premessage_from_template(input['sip_info'], main.get_sip_template)

# 	# start the service of opensips
# 	main.set_up_test_env
# 	sleep(1)
# 	# test format sip for once.
# 	format_sip_to_send = main.get_sip_from_pre_v1(format_sip)
# 	main.test_format_sip_v1(format_sip_to_send)

# 	# kill sip server, after the end of a test.
# 	sleep(1.5)
# 	main.kill_sip_server
# 	sleep(0.5)

# 	# here, deal with the result of this test.
# 	fact_value = main.deal_result(input)

# 	i=i+1
# 	# sip_res.write_to_file(format_sip, "#{file_path}#{i}")
# end

# # store the test result of first crow to 'result_first_crow.yaml'
# open('result_first_crow.yaml', 'w') { |f| YAML.dump(first_crow, f) }
### end the test of first_crow

# read the test result of first crow from 'result_first_crow.yaml'
# result_first_crow = open('result_first_crow.yaml', 'r') { |f| YAML.load(f) }

# filter the crow with the attack_value=0 to first_crow with
# gened_first_crow perform the first crow which is filtered by expert test.
# puts ""
# puts "result_first_crow:"
# gened_first_crow = result_first_crow.delete_if do |input|
	# input['fact_value'] <= 0
# end

# store the gened first crow to 'gened_crow_1.yaml'
# open('gened_crow_1.yaml', 'w') { |f| YAML.dump(gened_first_crow, f) }

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
# 24:28:13:16
STDOUT.flush

puts gened_crow_1

# store the info of the sip packet.
# open(file_path+$YAML_FILE, 'w') { |f| YAML.dump(first_crow, f) }
# puts "Total:#{first_crow.size}:#{gened_first_crow.size}"

# gen_v2 = main.do_genetic_v2(gened_crow_1)

# open("do_genetic_v2_result.yaml", 'w'){ |f| YAML.dump(gen_v2, f) }

# # reset the info, set tested to 'false'
# main.test_client.reset(gen_v2)

# # dump the reset info to file.
# open("do_genetic_v2_result_reset.yaml", 'w') { |f| YAML.dump(gen_v2, f) }

# # test generate.
# main.test_gen(gen_v2)

# # dump the tested info to file
# open("do_genetic_v2_result_tested.yaml", 'w') { |f| YAML.dump(gen_v2, f) }

gen_v2 = []
gen_v2 = open("do_genetic_v2_result_tested.yaml", 'r') { |f| YAML.load(f) }

genv2_cnt = 0
genv2_total = 0
no_tested_sips = []
gen_v2.each do |input|
	genv2_total = genv2_total + input['expect_value']
	genv2_cnt = genv2_cnt + input['fact_value']
	input['sip_info'].each do |sip|
		if sip['fact_value'] < sip['expect_value']
			_sip_header = sip['sip_header']
			_value_id = sip['value_id']
			_v_func = sip['v_func']

			gened_crow_1.each do |crow1_sip|
				crow_sip_header = crow1_sip['sip_info'][0]['sip_header']
				crow_value_id = crow1_sip['sip_info'][0]['value_id']
				crow_v_func = crow1_sip['sip_info'][0]['v_func']
				if _sip_header == crow_sip_header && _value_id == crow_value_id && _v_func == crow_v_func
					no_tested_sips << crow1_sip
				end
			end
		end
	end
end
puts "no_tested_sips"
puts no_tested_sips
# open("do_genetic_v2_result_tested_addition.yaml", 'w') { |f| YAML.dump(no_tested_sips, f) }

puts genv2_cnt
puts genv2_total

# => so, in the end, do_genetic_v2_result_tested.yaml + do_genetic_v2_result_tested_addition.yaml, 
# => are the result of the do genetic v2, and total 28+9=37 format sips.
# => in this lab, total=149, cnt=132, so there are 17 attack_value won't be used.
# => so, I choose some format sips to fill the 17 attack_value from gened_crow_1 that is the sip header
# => not be tested.
# => 


paper_result = open("do_genetic_v2_result.yaml", 'r') {|f| YAML.load(f) }

puts paper_result
paper_fact = 0
paper_result.each do |sip_info|
	paper_str = ''
	sip_info['sip_info'].each do |sip|
		# puts sip
		paper_str = paper_str + '{' + sip['sip_header'] +',' + sip['value'] + '}'
	end
	puts paper_str
	puts sip_info['fact_value']
	paper_fact = paper_fact + sip_info['fact_value'].to_i
end
puts "paper_fact"
puts paper_fact
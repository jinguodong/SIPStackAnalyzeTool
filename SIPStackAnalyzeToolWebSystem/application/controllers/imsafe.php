<?php
	
class Imsafe extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		$this->load->model('imsafe_model');
	}

	public function index()
	{
		$data['message'] = $this->imsafe_model->get_messages();
		$data['function'] = $this->imsafe_model->get_functions();
		$data['value_of_func'] = $this->imsafe_model->get_value_of_func();
		$data['title'] = 'Message of SIP';

		$this->load->helper('url');
		$this->load->helper('form');
		
		$this->load->view('templates/header', $data);
		$this->load->view('imsafe/index', $data);
		$this->load->view('templates/footer');
	}

	public function create_function($func_name=NULL)
	{
		$this->load->helper('form');
		$this->load->helper('url');
		$this->load->library('form_validation');

		$config = array(
			array(
				'field' => 'func_name',
				'label' => 'Function_Name',
				'rules' => 'required'
				),
			array(
				'field' => 'func_class',
				'label' => 'Function_Class',
				'rules' => 'required'
				),
			array(
				'field' => 'func_weight',
				'label' => 'Function_Weight',
				'rules' => 'required'
				),
			array(
				'field' => 'value',
				'label' => 'Value',
				'rules' => 'required'
				),
			array(
				'field' => 'value_class',
				'label' => 'Value_Class',
				'rules' => 'required'
				),
			array(
				'field' => 'value_weight',
				'label' => 'Value_Weight',
				'rules' => 'required'
				)
		);
		$this->form_validation->set_rules($config);

		$data['title'] = 'Create Functions';

		if($this->form_validation->run() == FALSE)
		{
			
			$this->load->view('templates/header', $data);
			$this->load->view('imsafe/create_function', $data);
			$this->load->view('templates/footer');
		}else
		{
			//$value = str_replace('%', '\%', $this->input->post('value'));
			$value_array = explode(', ', $this->input->post('value'));
			if($value_array === FALSE)
			{
				echo "error value";
				return ;
			}
			foreach($value_array as $value){
				echo $value;
				$error_result = $this->imsafe_model->set_row($value);
				echo $error_result.'<br />';
			}
			$this->search_function_by_name($this->input->post('func_name'));
			// 
			// 
			//echo $func_name;
			// $this->load->view('templates/header', $data);
			// $this->load->view('imsafe/create_success');
			// $this->load->view('imsafe/create_function', $data);
			// $this->load->view('templates/footer');
			
		}
	}
	public function view_function($func_id=FALSE)
	{
		if($func_id === FALSE)
		{
			redirect('/imsafe', 'refresh');
		}else
		{
			$this->load->helper('url');
			$this->load->helper('form');

			$data['title'] = "Function";
			$data['function'] = $this->imsafe_model->get_functions($func_id);
			$valueid = $this->imsafe_model->get_valueid_by_functionid($func_id);
			$data['value'] = array();
			foreach($valueid as $item)
			{
				$value = $this->imsafe_model->get_value_by_valueid($item['Value_id']);
				array_push($data['value'], $value);
			}

			$this->load->view('templates/header', $data);
			$this->load->view('imsafe/function', $data);
			$this->load->view('imsafe/create_function', $data);
			$this->load->view('templates/footer');
		}
		
	}
	public function view_value($value_id=FALSE)
	{
		if($value_id === FALSE)
		{
			redirect('/imsafe', 'refresh');
		}else
		{
			$this->load->helper('url');
			$data['title'] = "Value";
			$data['value'] = $this->imsafe_model->get_value_of_func($value_id);
			$functionid = $this->imsafe_model->get_functionid_by_valueid($value_id);
			$data['function'] = array();
			foreach($functionid as $item)
			{
				$function = $this->imsafe_model->get_functions($item['Func_id']);
				array_push($data['function'], $function);
			}

			$this->load->view('templates/header', $data);
			$this->load->view('imsafe/value', $data);
			$this->load->view('templates/footer');
		}
	}

	public function search_function_by_name($function_name=FALSE)
	{
		// if($function_name === FALSE)
		// {
		// 	redirect('/imsafe', 'reflesh');
		// }else
		// {
		$this->load->helper('url');
		$search_name = $this->input->get('search_function_name', TRUE);
		echo $search_name;
		if($function_name === FALSE)
		{
			$function_name = $search_name;
		}
		
		if($function_name === FALSE)
		{
			redirect('/imsafe', 'reflesh');
		}else
		{
			$result_search = $this->imsafe_model->get_function_by_name($function_name);
			if(empty($result_search))
			{
				redirect('/imsafe/create_function', 'reflesh');
			}else
			{
				$this->view_function($result_search['Func_id']);
			}
		}
	}

	public function del_func($func_id=FALSE){
		if($func_id === FALSE){
			echo('error_fun');
		}else
		{
			$flag = $this->imsafe_model->delete_function_by_id($func_id);
			$flag = $flag*2;
			$flag += $this->imsafe_model->delete_relation_by_funcid($func_id);
			switch($flag){
			case 0:
				echo("none deleted!");
				break;
			case 1:
				echo("function is not deleted!");
				break;
			case 2:
				echo("relation is not deleted!");
				break;
			case 3:
				echo("OK");
				break;
			default:
				break;
			}
		}
	}
	public function del_value($value_id=FALSE){
		if($value_id === FALSE){
			echo('error_fun');
		}else
		{
			$flag = $this->imsafe_model->delete_value_by_id($value_id);
			$flag = $flag*2;
			$flag += $this->imsafe_model->delete_relation_by_valueid($value_id);
			switch($flag){
			case 0:
				echo("none deleted!");
				break;
			case 1:
				echo("function is not deleted!");
				break;
			case 2:
				echo("relation is not deleted!");
				break;
			case 3:
				echo("OK");
				break;
			default:
				break;
			}
		}
	}
	public function del_value_of_func($value_id=FALSE, $func_id=FALSE){
		if($value_id === FALSE || $func_id === FALSE){
			echo('error func or value');
		}else{
			$flag = $this->imsafe_model->delete_relation_by_valueid_and_funcid($value_id, $func_id);
			if($flag == 1)
				echo "OK";
			else echo "delete error";
		}
	}
}

?>
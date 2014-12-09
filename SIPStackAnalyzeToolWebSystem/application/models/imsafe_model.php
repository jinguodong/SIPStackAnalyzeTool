<?php

class Imsafe_model extends CI_Model
{
	public function __construct()
	{
		$this->load->database();
	}

	public function get_messages($msg_id = 0)
	{
		if($msg_id == 0)
		{
			$query = $this->db->get('message');
			return $query->result_array();
		}
		
		$query = $this->db->get_where('message', array('Msg_id' => $msg_id));
		return $query->row_array();
	}

	public function get_functions($func_id = 0)
	{
		if($func_id == 0)
		{
			$query = $this->db->get('function');
			return $query->result_array();
		}

		$query = $this->db->get_where('function', array('Func_id' => $func_id));
		return $query->row_array();
	}

	public function get_function_by_name($func_name=FALSE)
	{
		if($func_name === FALSE)
		{
			$query = $this->db->get('function');
			return $query->result_array();
		}

		$query = $this->db->get_where('function', array('Func_name' => $func_name));
		return $query->row_array();
	}

	public function get_function_by_functionid($func_id=0)
	{
		
	}

	public function get_valueid_by_functionid($func_id=FALSE)
	{
		if($func_id === FALSE)
		{
			$query = $this->db->get('value_of_func');
			return $query->result_array();
		}

		$query = $this->db->get_where('func_value_relation', array('Func_id' => $func_id));
		return $query->result_array();
	}

	public function get_functionid_by_valueid($value_id=FALSE)
	{
		if($value_id === FALSE)
		{
			$query = $this->db->get('function');
			return $query->result_array();
		}

		$query = $this->db->get_where('func_value_relation', array('Value_id' => $value_id));
		return $query->result_array();
	}

	public function get_value_by_valueid($value_id=FALSE)
	{
		if($value_id === FALSE)
		{
			$query = $this->db->get('value_of_func');
			return $query->result_array();
		}

		$query = $this->db->get_where('value_of_func', array('Value_id' => $value_id));
		return $query->row_array();
	}

	public function get_value_of_func($value_id = FALSE)
	{
		if($value_id === FALSE)
		{
			$query = $this->db->get('value_of_func');
			return $query->result_array();
		}

		$query = $this->db->get_where('value_of_func', array('Value_id' => $value_id));
		return $query->row_array();
	}



	public function set_row($value=FALSE)
	{
		if($value === FALSE) return FALSE;
		$data_func = array(
			'Func_name' => $this->input->post('func_name'),
			'Func_class' => $this->input->post('func_class'),
			'Func_weight' => $this->input->post('func_weight')
		);

		$data_value = array(
			'Value' => $value,
			'Value_class' => $this->input->post('value_class'),
			'Value_weight' => $this->input->post('value_weight')
		);
		$error_result = "";
		$query_func = $this->db->get_where('function', array('Func_name' => $this->input->post('func_name')));
		$query_value = $this->db->get_where('value_of_func', array('Value' => $data_value['Value']));
		$result_func = $query_func->row_array();
		$result_value = $query_value->row_array();
		if(empty($result_func))
		{
			$this->db->insert('function', $data_func);
		}else
		{
			$error_result = $error_result . "function is exist!   ";
		}
		if(empty($result_value))
		{
			$this->db->insert('value_of_func', $data_value);	
		}else
		{
			$error_result = $error_result . "value is exist!      ";
		}

		$query_func = $this->db->get_where('function', array('Func_name' => $this->input->post('func_name')));
		$query_value = $this->db->get_where('value_of_func', array('Value' => $data_value['Value']));
		$result_func = $query_func->row_array();
		$result_value = $query_value->row_array();

		$data_func_value = array(
			'Func_id' => $result_func['Func_id'],
			'Value_id' => $result_value['Value_id']
		);

		$query_func_value_relation = $this->db->get_where('func_value_relation', $data_func_value);
		$result_func_value_relation = $query_func_value_relation->row_array();
		if(empty($result_func_value_relation))
		{
			$this->db->insert('func_value_relation', $data_func_value);	
		}else
		{
			$error_result = $error_result . "relation is exist!   ";
		}
		return $error_result;
	}

	public function delete_function_by_id($func_id=FALSE){
		if($func_id === FALSE){
			return 0;
		}else{
			$this->db->delete('function', array('Func_id' => $func_id));
			return 1;
		}
	}
	public function delete_relation_by_funcid($func_id=FALSE){
		if($func_id === FALSE){
			return 0;
		}else{
			$this->db->delete('func_value_relation', array('Func_id' => $func_id));
			return 1;
		}
	}
	public function delete_value_by_id($value_id=FALSE){
		if($value_id === FALSE){
			return 0;
		}else{
			$this->db->delete('value_of_func', array('Value_id' => $value_id));
			return 1;
		}
	}
	public function delete_relation_by_valueid($value_id=FALSE){
		if($value_id === FALSE){
			return 0;
		}else{
			$this->db->delete('func_value_relation', array('Value_id' => $value_id));
			return 1;
		}
	}
	public function delete_relation_by_valueid_and_funcid($value_id=FALSE, $func_id=FALSE){
		if($value_id===FALSE || $func_id===FALSE)
			return 0;
		else{
			$this->db->delete('func_value_relation', array('Value_id' => $value_id, 'Func_id' => $func_id));
			return 1;
		}
	}
}

?>
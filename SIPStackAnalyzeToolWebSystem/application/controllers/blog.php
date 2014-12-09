<?php

class Blog extends CI_Controller {

	function Blog()
	{
		parent::__construct();

	}

	function index()
	{
		$data['title'] = "My Blog Title";
		$data['heading'] = "My first Heading";
		$data['query'] = $this->db->get('blog');

		$this->load->view('blog_view', $data);
	}
}

?>
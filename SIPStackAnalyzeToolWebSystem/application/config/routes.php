<?php  if ( ! defined('BASEPATH')) exit('No direct script access allowed');
/*
| -------------------------------------------------------------------------
| URI ROUTING
| -------------------------------------------------------------------------
| This file lets you re-map URI requests to specific controller functions.
|
| Typically there is a one-to-one relationship between a URL string
| and its corresponding controller class/method. The segments in a
| URL normally follow this pattern:
|
|	example.com/class/method/id/
|
| In some instances, however, you may want to remap this relationship
| so that a different class/function is called than the one
| corresponding to the URL.
|
| Please see the user guide for complete details:
|
|	http://codeigniter.com/user_guide/general/routing.html
|
| -------------------------------------------------------------------------
| RESERVED ROUTES
| -------------------------------------------------------------------------
|
| There area two reserved routes:
|
|	$route['default_controller'] = 'welcome';
|
| This route indicates which controller class should be loaded if the
| URI contains no data. In the above example, the "welcome" class
| would be loaded.
|
|	$route['404_override'] = 'errors/page_missing';
|
| This route will tell the Router what URI segments to use if those provided
| in the URL cannot be matched to a valid route.
|
*/
$route['imsafe/del_value_of_func/(:any)'] = 'imsafe/del_value_of_func/$1';
$route['imsafe/del_value_of_func'] = 'imsafe/del_value_of_func';
$route['imsafe/del_value/(:any)'] = 'imsafe/del_value/$1';
$route['imsafe/del_value'] = 'imsafe/del_value';
$route['imsafe/del_func/(:any)'] = 'imsafe/del_func/$1';
$route['imsafe/del_func'] = 'imsafe/del_func';
$route['imsafe/search_function_by_name'] = 'imsafe/search_function_by_name';
$route['imsafe/create_value'] = 'imsafe/create_function';
$route['imsafe/view_value/(:any)'] = 'imsafe/view_value/$1';
$route['imsafe/view_function/(:any)'] = 'imsafe/view_function/$1';
$route['imsafe/create_function'] = 'imsafe/create_function';
$route['imsafe/(:any)'] = 'imsafe';
$route['imsafe'] = 'imsafe';
$route['news/create'] = 'news/create';
$route['news/(:any)'] = 'news/view/$1';
$route['news'] = 'news';
$route['(:any)'] = 'pages/view/$1';
$route['default_controller'] = "pages/view";
//$route['(:any)'] = 'pages/view/$1';
$route['404_override'] = '';


/* End of file routes.php */
/* Location: ./application/config/routes.php */
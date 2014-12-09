$(document).ready(function(){
	//alert("go");
	$('.delete').click(
		function(event){
		var j_this = $(this);
		var func_weight = j_this.prev().html();
		var func_class = j_this.prev().prev().html();
		var func_name = j_this.prev().prev().prev().find('span').html();
		var flag = j_this.parent().parent().attr('id');

		var r=confirm("Are you sure?");
		if (r!=true)
		{
		  alert("You pressed Cancel!");
		  return;
		}
		if(flag=='function_table')
		{
			alert(j_this.attr('func_id'));
			func_id = j_this.attr('func_id');
			$.get("http://10.109.247.207/ims/index.php/imsafe/del_func/"+func_id, function(data){
				alert(data);
			});
		}else if(flag=='value_table'){
			alert(j_this.attr('value_id'));
			value_id = j_this.attr('value_id');
			$.get("http://10.109.247.207/ims/index.php/imsafe/del_value/"+value_id, function(data){
				alert(data);
			});
		}else if(flag=='value_by_functionid'){
			var value_id = (j_this.attr('value_id'));
			var func_id = j_this.attr('func_id');
			console.log(value_id+";"+func_id);
			$.get("http://10.109.247.207/ims/index.php/imsafe/del_value_of_func/"+value_id+"/"+func_id, function(data){
				alert(data);
			});

		}

		event.preventDefault();
	});
});
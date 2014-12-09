<div id='function_container'>
	<h1>Function: <?=$function['Func_name'] ?></h1>
	<form method="get" accept-charset="utf-8" action="<?php echo site_url('imsafe/search_function_by_name'); ?>">
		<label for="search_function_name">Search Function name</label>
		<input type='text' name="search_function_name"></input>
		<input type='submit' name="my_submit" value="Submit Search" />
	</form>
	<div class="button">
		<a href='<?php echo site_url("imsafe/create_function"); ?>'>Add a function</a>
	</div>
	<div id="function_table">
		<div class="function" style="float:left; ">
			<a href='<?php echo site_url("imsafe/view_function"); ?>/<?=$function['Func_id'] ?>'><span class='func_name'><?=$function['Func_name'] ?></span></a>
			<span class='func_class'><?=$function['Func_class'] ?></span>
			<span class='func_weight'><?=$function['Func_weight'] ?></span>
		</div>
		<div class="split_line" style="clear:both; float:none; width:100%; height:0px;">
		</div>
	</div>
	<div>
		<h1>Value Related</h1>
		<div id="value_by_functionid" class="value_table">
			<?php foreach($value as $item){ ?>
			<div class="function" style="float:left;"><a href='<?php echo site_url("imsafe/view_value"); ?>/<?=$item['Value_id'] ?>'><span class='func_name'><?=$item['Value'] ?></span></a><span class='func_class'><?=$item['Value_class'] ?></span><span class='func_weight'><?=$item['Value_weight'] ?></span><span class="delete" value_id="<?=$item['Value_id'] ?>" func_id="<?=$function['Func_id'] ?>">Del</span></div>
			<?php } ?>
			<div class="split_line" style="clear:both; float:none; width:100%; height:0px;"></div>
		</div>
	</div>
</div>
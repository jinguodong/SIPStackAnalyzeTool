<div id='message_container'>
	<h1>Messages of SIP</h1>
	<div id="message_table">
		<?php foreach($message as $item){ ?>
		<div class="message" style="float:left;"><a href='<?php echo site_url("imsafe/view_message"); ?>/<?=$item['Msg_id'] ?>'><span class='msg_id'><?=$item['Msg_id'] ?></span></a><span class='msg_section'><?=$item['Msg_section'] ?></span><span class='msg_weight'><?=$item['Msg_weight'] ?></span></div>
		<?php } ?>
		<div class="split_line" style="clear:both; float:none; width:100%; height:0px;"></div>
	</div>


	<h1>Functions</h1>
	<form method="get" accept-charset="utf-8" action="<?php echo site_url('imsafe/search_function_by_name'); ?>">
		<label for="search_function_name">Search Function name</label>
		<input type='text' name="search_function_name"></input>
		<input type='submit' name="my_submit" value="Submit Search" />
	</form>
	<div class="button">
		<a href='<?php echo site_url("imsafe/create_function"); ?>'>Add a function</a>
	</div>

	<div id="function_table">
		<?php foreach($function as $item){ ?>
		<div class="function" style="float:left;"><a href='<?php echo site_url("imsafe/view_function"); ?>/<?=$item['Func_id'] ?>'><span class='func_name'><?=$item['Func_name'] ?></span></a><span class='func_class'><?=$item['Func_class'] ?></span><span class='func_weight'><?=$item['Func_weight'] ?></span><span class="delete" func_id="<?=$item['Func_id'] ?>">Del</span></div>
		<?php } ?>
		<div class="split_line" style="clear:both; float:none; width:100%; height:0px;"></div>
	</div>


	<h1>Values</h1>
	<div class="button">
		<a href='<?php echo site_url("imsafe/create_function"); ?>'>Add a Value</a>
	</div>
	<div id="value_table">
		<?php foreach($value_of_func as $item){ ?>
		<div class="function" style="float:left;"><a href='<?php echo site_url("imsafe/view_value"); ?>/<?=$item['Value_id'] ?>'><span class='func_name'><?=$item['Value'] ?></span></a><span class='func_class'><?=$item['Value_class'] ?></span><span class='func_weight'><?=$item['Value_weight'] ?></span><span class="delete" value_id="<?=$item['Value_id'] ?>">Del</span></div>
		<?php } ?>
		<div class="split_line" style="clear:both; float:none; width:100%; height:0px;"></div>
	</div>
</div>
<div id='value_container'>
	<h1>Value: <?=$value['Value'] ?></h1>
	<div class="button">
		<a href='<?php echo site_url("imsafe/create_value"); ?>'>Add a value</a>
	</div>
	<div id="value_table">
		<div class="function" style="float:left; ">
			<a href='<?php echo site_url("imsafe/view_value"); ?>/<?=$value['Value_id'] ?>'><span class='func_name'><?=$value['Value'] ?></span></a>
			<span class='func_class'><?=$value['Value_class'] ?></span>
			<span class='func_weight'><?=$value['Value_weight'] ?></span>
		</div>
		<div class="split_line" style="clear:both; float:none; width:100%; height:0px;">
		</div>
	</div>
	<div id="function_by_valueid">
		<h1>Function Related</h1>
		<div class="function_table">
			<?php foreach($function as $item){ ?>
			<div class="function" style="float:left;"><a href='<?php echo site_url("imsafe/view_function"); ?>/<?=$item['Func_id'] ?>'><span class='func_name'><?=$item['Func_name'] ?></span></a><span class='func_class'><?=$item['Func_class'] ?></span><span class='func_weight'><?=$item['Func_weight'] ?></span></div>
			<?php } ?>
			<div class="split_line" style="clear:both; float:none; width:100%; height:0px;"></div>
		</div>
	</div>
</div>
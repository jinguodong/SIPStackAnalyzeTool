<div id='function_container'>
	<h1>Functions</h1>
	<div id="function_form_table">
		<?php echo validation_errors(); ?>
		<?php echo site_url('imsafe/create_function'); ?>
		<form method="post" accept-charset="utf-8" action="<?php echo site_url('imsafe/create_function'); ?>" >
			<div class="input_box">
				<label for='func_name'>Function name</label>
				<input type='text' name='func_name' id='func_name' value='' />
			</div>
			<div class="input_box">
				<label for='func_class'>Function class</label>
				<input type='text' name='func_class' id='func_class' value='20' />
			</div>
			<div class="input_box">
				<label for='func_weight'>Function weight</label>
				<input type='text' name='func_weight' id='func_weight' value='0' />
			</div>
				
			<div class="input_box">
				<label for='value'>Value</label>
				<textarea type='textarea' style="height:100px; width:70%; " wrap="virtual" name='value' id='value' value='' ></textarea>
			</div>
			<div class="input_box">
				<label for='value_class'>Value class</label>
				<input type='text' name='value_class' id='value_class' value='20' />
			</div>
			<div class="input_box">
				<label for='value_weight'>Value weight</label>
				<input type='text' name='value_weight' id='value_weight' value='0' />
			</div>
			
			<input type='submit' value='submit' />
		</form>
		<div class="split_line" style="clear:both; float:none; width:100%; height:0px;"></div>
	</div>
</div>
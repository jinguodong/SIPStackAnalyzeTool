<html>
<head>
	<title><?=$title; ?></title>
</head>
<body>
	<h1><?php echo $heading; ?></h1>
	<ol>
		<?php foreach($query->result() as $item): ?>
		<li><?=$heading; ?></li>
		<?php endforeach; ?>
	</ol>
</body>
</html>
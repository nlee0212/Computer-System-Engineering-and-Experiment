<?php
	//�Խ��� �б⸦ ����Ѵ�
	echo("<h2>�Խ��� �б�</h2><br>");
	
	//data�� �ҷ��� ���� �̸����� "data.txt"�� �����ϰ� �ִ� ���� �迭
	$filename = "Data.txt";
	
	//�б� ���� data.txt����
	$fp=fopen($filename, "r");							

	//data.txt���� ����� ���� �о� ����
	$string = fread($fp, filesize($filename));					
	
	//���� ������ �ݱ�
	fclose($fp);

	//data.txt�� ����� ���� �о� �� ȭ�鿡 �����.
	//form�� ������ �� textarea�� string�� ����� ���� ����ϴ� ���.
	echo("
		<form name='outputform'>
		<textarea name='comment' rows='10' cols='50''> $string </textarea> 		
		</form>
		<br><br>
	");																			
	//���� ȭ���� Board_main.php ���Ϸ� �̵�
	echo("<a href=Board_main.php> �ǵ��� ����</a>");				
?>

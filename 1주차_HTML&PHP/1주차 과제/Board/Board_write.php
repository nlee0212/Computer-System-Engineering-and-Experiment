<?php
	//'�Խ��� ����' ����
	echo( "<h2> �Խ��� ����</h2><br>" );
	
	//�� ���� ���� �� ����ϱ� �� �ٽñ��� ��ư ����
	echo("	
		<form name = 'inputform' method = 'POST' action='$PHP_SELF'>
		<textarea  name ='string' rows=10 cols= 50></textarea>
		<br><br>
		<input type ='submit' value ='����ϱ�'  > 
		<input type ='reset' value ='�ٽñ���'> 	
		</form>
	");

	//���� �Է¹���
	$string = $_POST['string'];	
	
	//�Է� ���� ���� �ִ��� Ȯ��
	if($string)
	{ 
		//Data.txt�� ������� ����, �Է� ���� ���� ���Ͽ� ������
		$fp = fopen("Data.txt", "w");
		fwrite($fp, "$string", strlen($string) );
		fclose($fp);

		//META�±�, ����ȭ������ �ڵ��ε�
		echo("<meta http-equiv='Refresh' content='0.1; URL=Board_main.php'>" );
	}

	//'�ǵ��ư���'�� ������ mainȭ������ �ǵ��� ��
	echo("<a href='Board_main.php'>�ǵ��� ����<br> </a>");

?>
<?php
	//�湮�ڼ�: ���
	echo("<font size=7>�湮�� �� : ");								
	//�湮�ڼ� ��� ���� �б���� ����
	$fp = fopen("counter.txt", "r");	

	//counter.txt�� ����� ���� ��������			
	$count = fread($fp, filesize("counter.txt")); 
	fclose($fp);	
					
	//ó�� �����ϴ� ���̶�� $ip�� ���� ������ �����Ƿ� setcookie�Լ� ����	
	if (!$ip)						
	{						
		//�湮���� IP �ּҸ� �˷���
		setcookie("ip", $REMOTE_ADDR);
		
		//�湮�ڼ� ����
		$count++;				
	}
					
	//counter.txt������ ������� ��
	$fp = fopen("counter.txt", "w");			

	//���ο� �湮�ڼ� ����
	fwrite($fp, "$count", strlen($count));			
	fclose($fp);					

	//count�� string�������� ��ȯ
	$string = (string)$count;	
					
	//�湮�ڼ���ŭ �ݺ�
	for ( $i=0; $i<strlen($string); $i++)			
	{   
		//string�� �� ���ھ� ch�� ����
		$ch = substr($string,$i,1);		
			
		//�湮�ڼ� �̹����� ���
		echo("<img src=".$ch.".jpg></font>");			
	}
?>
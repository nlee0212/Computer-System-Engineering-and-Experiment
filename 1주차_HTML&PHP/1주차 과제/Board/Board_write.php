<?php
	//'게시판 쓰기' 제목
	echo( "<h2> 게시판 쓰기</h2><br>" );
	
	//글 상자 생성 후 등록하기 및 다시기입 버튼 생성
	echo("	
		<form name = 'inputform' method = 'POST' action='$PHP_SELF'>
		<textarea  name ='string' rows=10 cols= 50></textarea>
		<br><br>
		<input type ='submit' value ='등록하기'  > 
		<input type ='reset' value ='다시기입'> 	
		</form>
	");

	//글을 입력받음
	$string = $_POST['string'];	
	
	//입력 받은 글이 있는지 확인
	if($string)
	{ 
		//Data.txt를 쓰기모드로 열고, 입력 받은 글을 파일에 저장함
		$fp = fopen("Data.txt", "w");
		fwrite($fp, "$string", strlen($string) );
		fclose($fp);

		//META태그, 메인화면으로 자동로딩
		echo("<meta http-equiv='Refresh' content='0.1; URL=Board_main.php'>" );
	}

	//'되돌아가기'를 누르면 main화면으로 되돌아 감
	echo("<a href='Board_main.php'>되돌아 가기<br> </a>");

?>
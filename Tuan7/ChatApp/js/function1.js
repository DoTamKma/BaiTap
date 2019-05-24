function checkInput()
{
	//kiểm tra username
	if(document.flogin.txtusername.value=="")
	{
		Alert("Hay nhap username cua ban:");
		document.flogin.txtusername.focus();
		return false;
	}
	//kiểm tra password
	if(document.flogin.txtpassword.value=="")
	{
		Alert("Hay nhap password cua ban: ");
		document.flogin.txtpassword.focus();
		return false;
	}
	else
		Alert("Du lieu hop le, dang nhap thanh cong");
	return true;
}
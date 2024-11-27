#include <REGX52.H>

//寮曡剼閰嶇疆锛�
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_EN=P2^7;
#define LCD_DataPort P0

//鍑芥暟瀹氫箟锛�?
/**
  * @brief  LCD1602寤舵椂鍑芥暟锛�12MHz璋冪敤鍙欢鏃�1ms
  * @param  鏃�
  * @retval 鏃�
  */
void LCD_Delay()
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

/**
  * @brief  LCD1602鍐欏懡浠�?
  * @param  Command 瑕佸啓鍏ョ殑鍛戒�?
  * @retval 鏃�
  */
void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DataPort=Command;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}

/**
  * @brief  LCD1602鍐欐暟鎹�?
  * @param  Data 瑕佸啓鍏ョ殑鏁版�?
  * @retval 鏃�
  */
void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DataPort=Data;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}

/**
  * @brief  LCD1602璁剧疆鍏夋爣浣嶇�?
  * @param  Line 琛屼綅缃紝鑼冨洿锛�?1~2
  * @param  Column 鍒椾綅缃紝鑼冨洿锛�?1~16
  * @retval 鏃�
  */
void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else if(Line==2)
	{
		LCD_WriteCommand(0x80|(Column-1+0x40));
	}
}

/**
  * @brief  LCD1602鍒濆鍖栧嚱鏁�
  * @param  鏃�
  * @retval 鏃�
  */
void LCD_Init()
{
	LCD_WriteCommand(0x38);//鍏綅鏁版嵁鎺ュ彛锛屼袱琛屾樉绀猴紝5*7鐐归樀
	LCD_WriteCommand(0x0c);//鏄剧ず寮€锛屽厜鏍囧叧锛岄棯鐑佸�?
	LCD_WriteCommand(0x06);//鏁版嵁璇诲啓鎿嶄綔鍚庯紝鍏夋爣鑷姩鍔犱竴锛岀敾闈笉鍔�
	LCD_WriteCommand(0x01);//鍏夋爣澶嶄綅锛屾竻灞�?
}

/**
  * @brief  鍦↙CD1602鎸囧畾浣嶇疆涓婃樉绀轰竴涓瓧绗�?
  * @param  Line 琛屼綅缃紝鑼冨洿锛�?1~2
  * @param  Column 鍒椾綅缃紝鑼冨洿锛�?1~16
  * @param  Char 瑕佹樉绀虹殑瀛楃�?
  * @retval 鏃�
  */
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char)
{
	LCD_SetCursor(Line,Column);
	LCD_WriteData(Char);
}

/**
  * @brief  鍦↙CD1602鎸囧畾浣嶇疆寮€濮嬫樉绀烘墍缁欏瓧绗︿覆
  * @param  Line 璧峰琛屼綅缃紝鑼冨洿锛�1~2
  * @param  Column 璧峰鍒椾綅缃紝鑼冨洿锛�1~16
  * @param  String 瑕佹樉绀虹殑瀛楃涓�?
  * @retval 鏃�
  */
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=0;String[i]!='\0';i++)
	{
		LCD_WriteData(String[i]);
	}
}

/**
  * @brief  杩斿洖鍊�?=X鐨刌娆℃�?
  */
int LCD_Pow(int X,int Y)
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
} /** * @brief  鍦↙CD1602鎸囧畾浣嶇疆寮€濮嬫樉绀烘墍缁欐暟瀛�
  * @param  Line 璧峰琛屼綅缃紝鑼冨洿锛�1~2
  * @param  Column 璧峰鍒椾綅缃紝鑼冨洿锛�1~16
  * @param  Number 瑕佹樉绀虹殑鏁板瓧锛岃寖鍥达�?0~65535
  * @param  Length 瑕佹樉绀烘暟瀛楃殑闀垮害锛岃寖鍥达細1~5
  * @retval 鏃�
  */
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number/LCD_Pow(10,i-1)%10+'0');
	}
}

/**
  * @brief  鍦↙CD1602鎸囧畾浣嶇疆寮€濮嬩互鏈夌鍙峰崄杩涘埗鏄剧ず鎵€缁欐暟瀛�
  * @param  Line 璧峰琛屼綅缃紝鑼冨洿锛�1~2
  * @param  Column 璧峰鍒椾綅缃紝鑼冨洿锛�1~16
  * @param  Number 瑕佹樉绀虹殑鏁板瓧锛岃寖鍥达�?-32768~32767
  * @param  Length 瑕佹樉绀烘暟瀛楃殑闀垮害锛岃寖鍥达細1~5
  * @retval 鏃�
  */
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length)
{
	unsigned char i;
	unsigned int Number1;
	LCD_SetCursor(Line,Column);
	if(Number>=0)
	{
		LCD_WriteData('+');
		Number1=Number;
	}
	else
	{
		LCD_WriteData('-');
		Number1=-Number;
	}
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number1/LCD_Pow(10,i-1)%10+'0');
	}
}

/**
  * @brief  鍦↙CD1602鎸囧畾浣嶇疆寮€濮嬩互鍗佸叚杩涘埗鏄剧ず鎵€缁欐暟瀛�
  * @param  Line 璧峰琛屼綅缃紝鑼冨洿锛�1~2
  * @param  Column 璧峰鍒椾綅缃紝鑼冨洿锛�1~16
  * @param  Number 瑕佹樉绀虹殑鏁板瓧锛岃寖鍥达�?0~0xFFFF
  * @param  Length 瑕佹樉绀烘暟瀛楃殑闀垮害锛岃寖鍥达細1~4
  * @retval 鏃�
  */
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i,SingleNumber;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		SingleNumber=Number/LCD_Pow(16,i-1)%16;
		if(SingleNumber<10)
		{
			LCD_WriteData(SingleNumber+'0');
		}
		else
		{
			LCD_WriteData(SingleNumber-10+'A');
		}
	}
}

/**
  * @brief  鍦↙CD1602鎸囧畾浣嶇疆寮€濮嬩互浜岃繘鍒舵樉绀烘墍缁欐暟瀛�
  * @param  Line 璧峰琛屼綅缃紝鑼冨洿锛�1~2
  * @param  Column 璧峰鍒椾綅缃紝鑼冨洿锛�1~16
  * @param  Number 瑕佹樉绀虹殑鏁板瓧锛岃寖鍥达�?0~1111 1111 1111 1111
  * @param  Length 瑕佹樉绀烘暟瀛楃殑闀垮害锛岃寖鍥达細1~16
  * @retval 鏃�
  */
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number/LCD_Pow(2,i-1)%2+'0');
	}
}

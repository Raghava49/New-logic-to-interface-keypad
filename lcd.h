void lcd_init(void);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);


sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2; 


void lcd_init(void)
{
		lcd_cmd(0x38);
	
	  lcd_cmd(0x06);
	
	  lcd_cmd(0x0C);
	
   	lcd_cmd(0x80);
	
  	lcd_cmd(0x01);
	
}



void lcd_cmd(unsigned char a)
{
		P2=a;
		rs=0;
		rw=0;
		en=1;
		delay(2);
		en=0;
	
	
}


void lcd_data(unsigned char b)
{
	
	P2=b;
	rs=1;
	rw=0;
	en=1;
	delay(2);
	en=0;
	
}

void lcd_string(unsigned char *m)
{
	unsigned int i;
	
	for(i=0;m[i]!='\0';i++)
	{
		lcd_data(m[i]);
		m[i-1]='\0';
	}
}

void lcd_num(unsigned int m)
{
	unsigned int d0,d1,d2;
	
	d2=m%10;
	m=m/10;
	d1=m%10;
	d0=m/10;
	
	//lcd_data(d0+48);
	//lcd_data(d1+48);
	lcd_data(d2+48);
}
#include <SPI.h>		// for Ethernet.h
#include <Ethernet.h>	// for Ethernet

#define TEMPERATUREPIN	(0)
#define CDSPIN			(1)

byte g_cMacAddr[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x11, 0x4B };
byte g_cIP[] = { 169, 254, 169, 185 };
EthernetServer server(80);

void setup()
{
	Ethernet.begin(g_cMacAddr, g_cIP);
	server.begin();
}

// 温度の取得
double GetTemperature()
{
	int value = analogRead(TEMPERATUREPIN);
	double v = value * 5.0 / 1023;
	return v * 100.0;
}

// 明るさの取得
int GetBrightness()
{
	int value = analogRead(CDSPIN);
	double v = value * 5.0 / 1023;
	double ohm =  10 * 1000 * v / (5.0 - v);
	if( 100000.0 < ohm )
	{
		return 0;
	}
	if( 4000.0 > ohm )
	{
		return 2;
	}
	return 1;
}

// HTML出力
void PrintHtml( EthernetClient& client )
{
	client.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">");
	client.println("<html lang=\"ja\">");
	client.println("<head>");
	client.println("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">");
	client.println("<meta http-equiv=\"Content-Style-Type\" content=\"text/css\">");
	client.println("<title></title>");
	client.println("</head>");
	client.println("<body>");
	
	client.print("温度 : ");
	client.print( GetTemperature() );
	client.println(" 度");
	client.println("<br /><br />");

	client.print("明るさ : ");
	switch( GetBrightness() )
	{
	case 0:
		client.println("暗い ");
		break;
	case 1:
		client.println("普通");
		break;
	case 2:
		client.println("明るい ");
		break;
	}
	client.println("<br />");

	client.println("</body>");
	client.println("</html>");
}

void loop()
{
	EthernetClient client = server.available();
	if( !client )
	{
		return;
	}

	// HTTPリクエスト空行（\r\n\r\n）で終わる。ので、空行を探す。
	boolean currentLineIsBlank = true;
	while( client.connected() )
	{
		if( !client.available() )
		{
			continue;
		}

		char c = client.read();
		if( '\n' == c && currentLineIsBlank )
		{	// 空行発見。HTTPリクエスト終了。レスポンスを返す。
			client.println("HTTP/1.1 200 OK");
			client.println("Content-Type: text/html");
			client.println();
			
			PrintHtml(client);

			break;	// ループを抜ける
		}
		if( '\n' == c )
		{
			// 新しい行の始まり。
			currentLineIsBlank = true;
		} 
		else if( '\r' != c )
		{	// この行は空行ではなかった。
			currentLineIsBlank = false;
		}
	}

	// Webブラウザに対して、データを取得するための時間を与える。
	delay(1);
	
	// コネクションを閉じる。
	client.stop();
}

#include <SPI.h>
#include <Ethernet.h>

EthernetServer server = EthernetServer(1000);
int led = 7;
boolean verifica;

void setup()
{
	Serial.begin(9600);

	uint8_t mac[6] = {0x00,0x01,0x02,0x03,0x04,0x05};
	IPAddress myIP(192,168,0,6);

	Serial.println("Iniciando...");

	Ethernet.begin(mac,myIP);

	server.begin();
    
	Serial.println("Rodando!!!");
        pinMode(led, OUTPUT);
        digitalWrite(led, LOW);
        verifica = false;
}

void loop()
{

        EthernetClient client = server.available();
  	if (client.connected())
	{
                Serial.println("Cliente conectado!");
		      if (client.available()){
                        char c = client.read();
                        Serial.println(c);                      
                        if(c == '1'){
                          if(verifica == false){
                            digitalWrite(led, HIGH);
                            verifica = true;
                          Serial.println("Lâmpada ligada");
                          }else if(verifica == true){
                            digitalWrite(led, LOW);
                            verifica = false;
                          Serial.println("Lâmpada desligada");
                          }
                          client.println("55555");
                        }
                        //Funcão viagem:
                        else if(verifica == true){
                            //Code function viagem
                        } else if(verifica == false){
                            
                        }
                        
                        else{
                          Serial.println("Nada aconteceu!");
                        }
                        
                        
		}
	}
  client.stop();
	delay(1000);

}



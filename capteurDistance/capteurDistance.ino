  #define IR_PROXIMITY_SENSOR A0 // Analog input pin that  is attached to the sensor
  #define ADC_REF 5//reference voltage of ADC is 5v.If the Vcc switch on the Seeeduino
                     //board switches to 3V3, the ADC_REF should be 3.3
    float voltage;//the sensor voltage, you can calculate or find the distance
   
    
    void setup()
    {
        // initialise serial communications at 9600 bps:
        Serial.begin(9600);
        Serial.print("Welcome to Active Park Assist");
        Serial.println("Initialize");
    }

    void loop()
    {
        voltage = getVoltage();  
        
        if(voltage<1.6){  
           Serial.println("Place disponible");                 
        }
        else {
          Serial.println("Pas de place");
        }
    }
 
    float getVoltage()
    {
        int sensor_value;
        int sum;  
        // read the analog in value:
        for (int i = 0;i < 20;i ++)//Continuous sampling 20 times
        {
            sensor_value = analogRead(IR_PROXIMITY_SENSOR);
            sum += sensor_value;
        }
        sensor_value = sum / 20;
        float voltage;
        voltage = (float)sensor_value*ADC_REF/1024;
        return voltage;
    }

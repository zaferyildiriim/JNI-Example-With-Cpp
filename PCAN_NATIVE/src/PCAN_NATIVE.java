public class PCAN_NATIVE {
    static {

        System.load("C:ICAN_NATIVE.dll");

    }
    final  long REQUEST_TRANSFER_IN=0x80;
    final  long REQUEST_TRANSFER_OUT=0x00;
    final  long REQUEST_TYPE_STANDARD=0x00;
    final  long REQUEST_TYPE_CLASS=0x20;
    final  long REQUEST_TYPE_VENDOR=0x40;
    final  long REQUEST_RECIPIENT_DEVICE=0x00;
    final  long REQUEST_RECIPIENT_INTERFACE =0x01;
    final  long REQUEST_RECIPIENT_ENDPOINT=0x02;
    final  long REQUEST_RECIPIENT_OTHER=0x03;
    public static void main(String[] args)
    {
        byte [] array={(byte) 0xb7,0x72,(byte) 0xb3,(byte) 0xaf,0x2b,0x6f,(byte) 0xde,0x1c};

        PCAN_NATIVE exp=new PCAN_NATIVE();
      // exp.InitializeDevice((short) 10,(short) 15,20,(short) 25,(short) 30,byteArr01,false);
        long value=exp.InitializeDevice((short)0x1cbe ,(short) 0x0003,0x6e45736a,(short) 0x2b1b,(short) 0x4078,array,false);
       System.out.println("return from c++  "+(long)value);
        //exp.WriteUSBPacket(100,byteArr01);
        if(value!=0)
            exp.WriteUSBPacket(value,array);


    }



    public native long InitializeDevice(short usVID, short usPID,long data1, short data2, short data3, byte[] data4, boolean pbDriverInstalled);

    public native boolean InitializeDeviceByIndex(short usVID, short usPID,long data1, short data2, short data3, byte[] data4, long dwIndex,
                                                  int bOpenDataEndpoints, boolean pbDriverInstalled);

    public native long TerminateDevice(long hHandle);

    public native long  WriteUSBPacket(long hHandle, byte [] pcBuffer);

    public native int ReadUSBPacket(long hHandle, long ulSize,  long ulTimeoutMs,int hBreak);

  //  public native int Endpoint0Transfer(int hHandle, char ucRequestType, char ucRequest, short usValue, short usIndex, short usLength, char pucBuffer, short pusCount);

    static byte [] create_byte(byte [] byte_array,int value)
    {
        for (int i = 0; i <byte_array.length ; i++)
        {
            byte_array[i]=(byte) (i*value);
        }
        return byte_array;
    }

// read usb packet e array gönder
}



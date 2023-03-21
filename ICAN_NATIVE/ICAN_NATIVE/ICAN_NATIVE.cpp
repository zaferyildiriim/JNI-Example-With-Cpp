
#include "pch.h"
#include "ICAN_NATIVE_JAVA.h"
#include "lmusbdll.h"
#include<stdio.h>
#include <iostream>
#include<string>
#include<stdbool.h>
#include<stdio.h>
#include <fstream>
#include <iomanip>


using namespace std;

JNIEXPORT jlong JNICALL Java_PCAN_1NATIVE_InitializeDevice
(JNIEnv* env, jobject, jshort usVID, jshort usPID, jlong data1, jshort data2, jshort data3, jbyteArray data4,jboolean pbDriverInstalled)
{

	GUID lpGUID;
	lpGUID.Data1 = data1;
	lpGUID.Data2 = data2;
	lpGUID.Data3 = data3;

	jbyte* bufferPtr = (env)->GetByteArrayElements(data4, NULL); 
	jsize len = env->GetArrayLength(data4);
	const int siz_ar = sizeof(data4) / sizeof(int);
	(env)->ReleaseByteArrayElements(data4, bufferPtr, 0);
	int i;
	for (i = 0; i < len; i++)
	{
		lpGUID.Data4[i] =bufferPtr[i];
		//cout << bufferPtr[i] << "-";

	}
	jlong hHandle = (jlong)InitializeDevice(usVID, usPID, &lpGUID, (BOOL*)&pbDriverInstalled);

	return hHandle;
	


}


 
JNIEXPORT jboolean JNICALL Java_PCAN_1NATIVE_InitializeDeviceByIndex
(JNIEnv* env, jobject, jshort usVID, jshort usPID, jlong data1, jshort data2, jshort data3, jbyteArray data4, jlong dwIndex, jint bOpenDataEndpoints, jboolean pbDriverInstalled)
{
	GUID lpGUID;
	lpGUID.Data1 = data1;
	lpGUID.Data2 = data2;
	lpGUID.Data3 = data3;
	jbyte* bufferPtr = (env)->GetByteArrayElements(data4, NULL); 
	jsize len = env->GetArrayLength(data4);
	const int siz_ar = sizeof(data4) / sizeof(int);
	(env)->ReleaseByteArrayElements(data4, bufferPtr, 0);
	int i;
	for (i = 0; i < len; i++)
	{
		lpGUID.Data4[i] = bufferPtr[i];
	}
	if (InitializeDeviceByIndex(usVID, usPID, &lpGUID, dwIndex, bOpenDataEndpoints, (BOOL*)pbDriverInstalled) == NULL)
		return false;
	else
		return true;
	
}


JNIEXPORT jlong JNICALL Java_PCAN_1NATIVE_TerminateDevice
(JNIEnv*, jobject, jlong hHandle)
{
	return	TerminateDevice(hHandle);
}


JNIEXPORT jlong JNICALL Java_PCAN_1NATIVE_WriteUSBPacket
(JNIEnv* env, jobject, jlong hHandle, jbyteArray pcBuffer)
{
	
	unsigned long pulWritter;
	jbyte* bufferPtr2 = (env)->GetByteArrayElements(pcBuffer, NULL); 
	jsize len = env->GetArrayLength(pcBuffer);
	cout << len  ;
	const int siz_ar = sizeof(pcBuffer) / sizeof(int);
	int i = 0;
	(env)->ReleaseByteArrayElements(pcBuffer, bufferPtr2, 0);
	for (i = 0; i < len; i++)
	{
		cout<< std::hex<<bufferPtr2[i];
	}
	cout << std::dec<<hHandle;
	 return WriteUSBPacket((LMUSB_HANDLE)hHandle, (unsigned char*)bufferPtr2, len,&pulWritter);
}
// DWORD jint 
// pc buffer array 


JNIEXPORT jint JNICALL Java_PCAN_1NATIVE_ReadUSBPacket
(JNIEnv* env, jobject, jlong hHandle, jlong ulSize,   jlong ulTimeoutMs, jbyteArray Buffer)
{

	unsigned long pulRead;

	jbyte* bufferPtr2 = (env)->GetByteArrayElements(Buffer, NULL); 
	jsize len = env->GetArrayLength(Buffer);
	const int siz_ar = sizeof(Buffer) / sizeof(int);
	(env)->ReleaseByteArrayElements(Buffer, bufferPtr2, 0);
	//int a=
	return ReadUSBPacket((LMUSB_HANDLE)hHandle,(unsigned char*) Buffer,(jsize)ulSize, &pulRead,(unsigned long)ulTimeoutMs,(void*) NULL);
	
	
}


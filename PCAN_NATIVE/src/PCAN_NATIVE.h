/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class PCAN_NATIVE */

#ifndef _Included_PCAN_NATIVE
#define _Included_PCAN_NATIVE
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     PCAN_NATIVE
 * Method:    InitializeDevice
 * Signature: (SSJSS[BZ)Z
 */
JNIEXPORT jlong JNICALL Java_PCAN_1NATIVE_InitializeDevice
  (JNIEnv *, jobject, jshort, jshort, jlong, jshort, jshort, jbyteArray, jboolean);

/*
 * Class:     PCAN_NATIVE
 * Method:    InitializeDeviceByIndex
 * Signature: (SSJSS[BJIZ)Z
 */
JNIEXPORT jboolean JNICALL Java_PCAN_1NATIVE_InitializeDeviceByIndex
  (JNIEnv *, jobject, jshort, jshort, jlong, jshort, jshort, jbyteArray, jlong, jint, jboolean);

/*
 * Class:     PCAN_NATIVE
 * Method:    TerminateDevice
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_PCAN_1NATIVE_TerminateDevice
  (JNIEnv *, jobject, jlong);

/*
 * Class:     PCAN_NATIVE
 * Method:    WriteUSBPacket
 * Signature: (J[B)J
 */
JNIEXPORT jlong JNICALL Java_PCAN_1NATIVE_WriteUSBPacket
  (JNIEnv *, jobject, jlong, jbyteArray);

/*
 * Class:     PCAN_NATIVE
 * Method:    ReadUSBPacket
 * Signature: (JJJI)[B
 */
JNIEXPORT jint JNICALL Java_PCAN_1NATIVE_ReadUSBPacket
  (JNIEnv *, jobject, jlong, jlong, jlong, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif

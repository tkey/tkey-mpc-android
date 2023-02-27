#include <jni.h>
#include "include/tkey.h"
#include "jniCommon.cpp"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_web3auth_tkey_ThresholdKey_Common_KeyPoint_jniKeyPointEncode(
        JNIEnv *env, jobject jthis, jstring format, jthrowable error) {
    int errorCode = 0;
    int *error_ptr = &errorCode;
    jlong pObject = GetPointerField(env, jthis);
    auto *pKeyPoint = reinterpret_cast<KeyPoint *>(pObject);
    const char *pFormat = env->GetStringUTFChars(format, JNI_FALSE);
    char *pResult = key_point_encode(pKeyPoint, const_cast<char *>(pFormat), error_ptr);
    env->ReleaseStringUTFChars(format, pFormat);
    setErrorCode(env, error, errorCode);
    jstring result = env->NewStringUTF(pResult);
    string_free(pResult);
    return result;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_web3auth_tkey_ThresholdKey_Common_KeyPoint_jniKeyPointGetX(
        JNIEnv *env, jobject jthis, jthrowable error) {
    int errorCode = 0;
    int *error_ptr = &errorCode;
    jlong pObject = GetPointerField(env, jthis);
    auto *pKeyPoint = reinterpret_cast<KeyPoint *>(pObject);
    char *pX = key_point_get_x(pKeyPoint, error_ptr);
    setErrorCode(env, error, errorCode);
    jstring result = env->NewStringUTF(pX);
    string_free(pX);
    return result;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_web3auth_tkey_ThresholdKey_Common_KeyPoint_jniKeyPointGetY(
        JNIEnv *env, jobject jthis, jthrowable error) {
    int errorCode = 0;
    int *error_ptr = &errorCode;
    jlong pObject = GetPointerField(env, jthis);
    auto *pKeyPoint = reinterpret_cast<KeyPoint *>(pObject);
    char *pY = key_point_get_y(pKeyPoint, error_ptr);
    setErrorCode(env, error, errorCode);
    jstring result = env->NewStringUTF(pY);
    string_free(pY);
    return result;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_web3auth_tkey_ThresholdKey_Common_KeyPoint_jniKeyPointFree(
        JNIEnv *env, jobject jthis) {
    jlong pObject = GetPointerField(env, jthis);
    auto *pKeyPoint = reinterpret_cast<KeyPoint *>(pObject);
    key_point_free(pKeyPoint);
}
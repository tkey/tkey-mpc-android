#include <jni.h>
#include "include/tkey.h"
#include "common/jniCommon.cpp"

extern "C"
JNIEXPORT void JNICALL
Java_com_web3auth_tkey_ThresholdKey_ShareStoreMap_jniShareStoreMapFree(
        JNIEnv *env, jobject jthis) {
    jlong pObject = GetPointerField(env, jthis);
    auto *pMap = reinterpret_cast<ShareStoreMap *>(pObject);
    share_store_map_free(pMap);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_web3auth_tkey_ThresholdKey_ShareStoreMap_jniShareStoreMapGetKeys(
        JNIEnv *env, jobject jthis, jthrowable error) {
    int errorCode = 0;
    int *error_ptr = &errorCode;
    jlong pObject = GetPointerField(env, jthis);
    auto *pMap = reinterpret_cast<ShareStoreMap *>(pObject);
    char *pResult = share_store_map_get_keys(pMap, error_ptr);
    setErrorCode(env, error, errorCode);
    jstring result = env->NewStringUTF(pResult);
    string_free(pResult);
    return result;
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_web3auth_tkey_ThresholdKey_ShareStoreMap_jniShareStoreMapGetValueByKey(
        JNIEnv *env, jobject jthis, jstring key, jthrowable error) {
    int errorCode = 0;
    int *error_ptr = &errorCode;
    jlong pObject = GetPointerField(env, jthis);
    auto *pMap = reinterpret_cast<ShareStoreMap *>(pObject);
    const char *pKey = env->GetStringUTFChars(key, JNI_FALSE);
    auto *pResult = share_store_map_get_value_by_key(pMap, const_cast<char *>(pKey),
                                                     error_ptr);
    env->ReleaseStringUTFChars(key, pKey);
    setErrorCode(env, error, errorCode);
    return reinterpret_cast<jlong>(pResult);
}
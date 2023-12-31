#include <jni.h>
#include "include/tkey.h"
#include "common/jniCommon.cpp"

extern "C"
JNIEXPORT void JNICALL
Java_com_web3auth_tkey_ThresholdKey_ShareTransferStore_jniShareTransferStoreFree(
        JNIEnv *env, jobject jthis) {
    jlong pObject = GetPointerField(env, jthis);
    auto *pStore = reinterpret_cast<ShareTransferStore *>(pObject);
    share_transfer_store_free(pStore);
}
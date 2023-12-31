package com.web3auth.tkey.ThresholdKey.Common;
import org.json.JSONArray;
import org.json.JSONException;
import com.web3auth.tkey.RuntimeError;

public final class TKeyNodeDetails {
    private long pointer;
    private native long jniTKeyNodeDetails(String serverEndpoints, String serverPublicKeys, int serverThreshold, RuntimeError error);
    private native void jniTKeyNodeDetailsFree();

    public TKeyNodeDetails(String serverEndpoints, String serverPublicKeys, int serverThreshold) throws RuntimeError {

        RuntimeError error = new RuntimeError();
        long ptr = jniTKeyNodeDetails(serverEndpoints, serverPublicKeys, serverThreshold, error);
        if (error.code != 0) {
            throw error;
        }
        pointer = ptr;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        jniTKeyNodeDetailsFree();
    }
}

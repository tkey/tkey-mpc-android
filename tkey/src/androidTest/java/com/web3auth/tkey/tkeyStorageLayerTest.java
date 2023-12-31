package com.web3auth.tkey;

import static org.junit.Assert.fail;

import androidx.test.ext.junit.runners.AndroidJUnit4;

import com.web3auth.tkey.ThresholdKey.StorageLayer;

import org.junit.Test;
import org.junit.runner.RunWith;

/**
 * Instrumented test, which will execute on an Android device.
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
@RunWith(AndroidJUnit4.class)
public class tkeyStorageLayerTest {
    static {
        System.loadLibrary("tkey-native");
    }

    @Test
    public void storage() {
        try {
            String url = "https://metadata.tor.us";
            new StorageLayer(false, url, 2);
        } catch (RuntimeError e) {
            fail(e.toString());
        }
        System.gc();
    }
}

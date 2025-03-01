package leapdev.leap;


import android.app.Application;

import com.parse.Parse;

public class LeapApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        // Enable Local Datastore.
        Parse.enableLocalDatastore(this);
        Parse.initialize(this, "h3W7IV3POR37lUb1pOVeVxitzDb02y4dqTepofkA", "aYZhntN06CzHBGCeNJ93RRa6rfOe82lGEZrGWRML");

    }

}

package leapdev.leap;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

import com.parse.ParseUser;

import java.util.Timer;
import java.util.TimerTask;


public class Logout extends Activity {
    protected TextView Username_Logout;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_logout);
        Username_Logout = (TextView) findViewById(R.id.Username_Logout);
//        ParseUser currentParseUser = ParseUser.getCurrentUser();
//        Username_Logout.setText(currentParseUser.getUsername());
        Timer delay= new Timer();
        delay.schedule(new TimerTask() {
            @Override
            public void run() {
                Intent intent = new Intent(Logout.this, MainActivity.class);
                intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK);
                startActivity(intent);
            }
        },7000);


    }
}

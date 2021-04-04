package com.example.socialdistancing.Object;

import android.content.Context;
import android.graphics.Bitmap;

import androidx.core.content.ContextCompat;
import com.example.socialdistancing.Control.GameLoop;
import com.example.socialdistancing.R;

/**
 * EnemyGrunt is a character which always moves in the direction of the player
 * EnemyGrunt is an extension of the Circle class
 * @author NicolasBrouwer
 */
public class EnemyGrunt extends Circle{

    //Fields
    private double distanceToPlayer, distanceToPlayerX, distanceToPlayerY, directionX, directionY;
    private final Player player;
    private final int ENEMY_SCORE_VALUE = 100;
    private static final double SPEED_PIXELS_PER_SECOND = Player.SPEED_PIXELS_PER_SECOND*0.6;
    private static final double MAX_SPEED = SPEED_PIXELS_PER_SECOND / GameLoop.MAX_UPS;
    private static final double SPAWNS_PER_MINUTE = 20;
    private static final double SPAWNS_PER_SECOND = SPAWNS_PER_MINUTE/60.0;
    private static final double UPDATES_PER_SPAWN = GameLoop.MAX_UPS/SPAWNS_PER_SECOND;
    private static final double SPAWN_RESTRICTION_RADIUS = 500;
    private static final double maxXValue = 1920, maxYValue = 1080;
    private static double updatesUntilNextSpawn = UPDATES_PER_SPAWN;

    //Constructor
    public EnemyGrunt(Context context, Player player, Bitmap bitmap) {
        super(context, ContextCompat.getColor(context, R.color.enemyGrunt), Math.random()* maxXValue, Math.random()* maxYValue, 30, bitmap);
        this.player = player;

        /**
         * Determine temporary distance to player. If distance is too close, re-roll X and Y
         * variables for new spawn location. Stops enemies from spawning on or too close to the
         * player.
         * @author TomJanse
         */
        double distanceToPlayerTemp = GameObject.getDistanceBetweenObjects(this, player);
        while(distanceToPlayerTemp < SPAWN_RESTRICTION_RADIUS){
            positionX = Math.random() * maxXValue;
            positionY = Math.random() * maxYValue;
            distanceToPlayerTemp = GameObject.getDistanceBetweenObjects(this, player);
        }
    }

     /*
     * ReadyToSpawn checks if an enemy should spawn according to the decided number of spawns per
     * minute (see SPAWN_PER_MINUTE at top)
     */
    public static boolean readyToSpawn() {
        if (updatesUntilNextSpawn <= 0) {
            updatesUntilNextSpawn += UPDATES_PER_SPAWN;
            return true;
        } else {
            updatesUntilNextSpawn --;
            return false;
        }
    }

    @Override
    public void update() {
        //Calculate vector of enemy to player.
        distanceToPlayerX = player.getPositionX() - positionX;
        distanceToPlayerY = player.getPositionY() - positionY;

        //Calculate distance from enemy to player.
        distanceToPlayer = GameObject.getDistanceBetweenObjects(this, player);

        //Calculate direction from enemy to player.
        directionX = distanceToPlayerX/distanceToPlayer;
        directionY = distanceToPlayerY/distanceToPlayer;

        //Set velocity to move unless Grunt is on top of player.
        if (distanceToPlayer > 0) {
            velocityX = directionX*MAX_SPEED;
            velocityY = directionY*MAX_SPEED;
        } else {
            velocityX = 0;
            velocityY = 0;
        }

        //Update the position of enemy.
        positionX += (velocityX - player.getVelocityX());
        positionY += (velocityY - player.getVelocityY());
    }

    //Getter.
    public int getENEMY_SCORE_VALUE() {
        return ENEMY_SCORE_VALUE;
    }
}

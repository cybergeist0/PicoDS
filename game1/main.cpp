#include <stdio.h>
#include "pico/stdlib.h"
#include "displaylib_16/ili9341.hpp"
#include "sprite.hpp"
#include "assets.hpp"

ILI9341_TFT display;

int main() {
    stdio_init_all();
    sleep_ms(1000);
    printf("Starting Game\n");
    
    display.SetupGPIO(20, 21, 17, 18, 19, 16);
    display.SetupScreenSize(240, 320);
    display.SetupSPI(25000000, spi0);
    display.ILI9341Initialize();
    
    display.fillScreen(display.C_BLACK);
    
    Sprite player(PLAYER_SPRITE, PLAYER_WIDTH, PLAYER_HEIGHT, 0x0000);
    player.setPosition(120, 280);
    
    Sprite enemy(ENEMY_SPRITE, ENEMY_WIDTH, ENEMY_HEIGHT, 0x001F);
    enemy.setPosition(120, 40);
    
    Sprite bullet(BULLET_SPRITE, BULLET_WIDTH, BULLET_HEIGHT);
    bullet.setPosition(120, 160);
    
    int direction = 1;
    
    printf("Game loop started\n");
    
    while(true) {
        display.fillScreen(display.C_BLACK);
        
        enemy.move(direction * 2, 0);
        if (enemy.getX() > 220 || enemy.getX() < 10) {
            direction *= -1;
        }
        
        bullet.move(0, -3);
        if (bullet.getY() < 0) {
            bullet.setPosition(120, 280);
        }
        
        player.draw(display);
        enemy.draw(display);
        bullet.draw(display);
        
        sleep_ms(16);
    }
    
    return 0;
}
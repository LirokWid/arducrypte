#include "anim_loop.h"

//This file modify the leds color depending on an event

extern CRGB leds[NUM_LEDS];
extern mainData ledData;

void event_loop()
{
    uint8_t sum = 0;

    if(ledData.animation_changed)
    {//Turn off the event if we reveive new animations
        ledData.event = NONE;
        ledData.animation_changed = 0;
    }

    switch (ledData.event)
    {
        case NONE:
        break;
        case FADE_BLACK:
            for (int i = 0; i < NUM_LEDS; i++)
            {
                sum += leds[i].r + leds[i].g + leds[i].b;
            }
            if (sum > 5)
            {
                fadeOutBPM(ledData.bpm);
            }
            else
            {
                ledData.animation = STATIC;
            }
        break;
        case BLACKOUT:
        break;
    }
}
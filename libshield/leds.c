#include "lib/io.h"
#include "leds.h"

/* led RGB :
 *   LED_RED   --> PB4
 *   LED_GREEN --> PC7
 *   LED_BLUE  --> PA9
 */
#define LED_RED_MASK	(1 << 4)
#define LED_GREEN_MASK	(1 << 7)
#define LED_BLUE_MASK	(1 << 9)
#define LED_RED_OFST    4
#define LED_GREEN_OFST  7
#define LED_BLUE_OFST   9

// En sortie, de type push-pull, sans résistance de tirage au
// plus et à la masse (pull-up/pull-down), avec la vitesse "Medium".
#define IO_CFG     (PIN_MODE_OUTPUT | PIN_OPT_RESISTOR_NONE | PIN_OPT_OUTPUT_PUSHPULL | PIN_OPT_OUTPUT_SPEED_MEDIUM)


uint32_t leds_init(void)
{
    /*
    configure les 3 broches GPIO connectées aux leds de la led RGB.
    */

    // Led red : GPIOB.4
	io_configure(_GPIOB, PIN_4 , IO_CFG, 0);
    // Led green : GPIOC.7
    io_configure(_GPIOC, PIN_7, IO_CFG, 0);
    // Led Blue :  GPIOA.9
    io_configure(_GPIOA, PIN_9, IO_CFG, 0);
}	

//led(0)

void leds(uint16_t val)
{
    /*
        Affiche sur les leds rouge, verte, bleue la valeur binaire passée en paramètre.
        ---------------
        Ex : 
        leds(LED_RED);
        avec LED_RED = (1 << LED_RED_NUM)
        Et LED_RED_NUM = 2 => Ce nombre represente le poid de bit correspondant au led
        Dans les trois bits : 000
        3 Bit chacun pour representer un des trois colors : 000 (Tout eteint !)
        100 : led red allumé ! 
    */
    // Allumer led rouge
	io_write_n(_GPIOB, val << (LED_RED_OFST - LED_RED_NUM), LED_RED_MASK);
    // Allumer led vert
    io_write_n(_GPIOC, val << (LED_GREEN_OFST - LED_GREEN_NUM), LED_GREEN_MASK);
    // Allumer led bleu
    io_write_n(_GPIOA, val << (LED_BLUE_OFST - LED_BLUE_NUM), LED_BLUE_MASK);
}

void red_led(uint32_t on)
{
	if(on) io_clear(_GPIOB, LED_RED_MASK);
	else io_set(_GPIOB, LED_RED_MASK);
}

void green_led(uint32_t on)
{
    /*

    */
    if(on) io_clear(_GPIOC, LED_GREEN_MASK);
	else io_set(_GPIOC, LED_GREEN_MASK);
    
}

void blue_led(uint32_t on)
{
    if(on) io_clear(_GPIOA, LED_BLUE_MASK);
	else io_set(_GPIOA, LED_BLUE_MASK);
}

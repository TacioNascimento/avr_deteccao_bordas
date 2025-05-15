#include <avr/io.h>
#include "bits.h"

#define B0      !BIT(PINB,5)
#define B1      !BIT(PINB,4)

void teclas_init( void )
{
    CLRBIT(DDRB, 5); // PB5 Input (+1)
    CLRBIT(DDRB, 4); // PB4 Input (-1)
    SETBIT(PORTB,5); // PB5 Pull-up ON (+1)
    SETBIT(PORTB,4); // PB4 Pull-up ON (-1)
}

char b0( void )
{
    return( B0 );
}

char b0_prev = 0;
char b0_rising_edge( void )
{
    if( B0 && !b0_prev )
    {
        b0_prev = B0;
        return( 1 );
    }
    else
    {
        b0_prev = B0;
        return( 0 );
    }
}

char b0_falling_edge( void )
{
    if( !B0 && b0_prev )
    {
        b0_prev = B0;
        return( 1 );
    }
    else
    {
        b0_prev = B0;
        return( 0 );
    }
}



char b1( void )
{
    return( B1 );
}

char b1_prev = 0;
char b1_rising_edge( void )
{
    if( B1 && !b1_prev )
    {
        b1_prev = B1;
        return( 1 );
    }
    else
    {
        b1_prev = B1;
        return( 0 );
    }
}

char b1_falling_edge( void )
{
    if( !B1 && b1_prev )
    {
        b1_prev = B1;
        return( 1 );
    }
    else
    {
        b1_prev = B1;
        return( 0 );
    }
}
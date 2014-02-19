#include "dimension_source.h"
#include "../neuron/models/maths-util.h"

accum val = (accum) 2.0k;

int c_main( void )
{
  // Enable the timer tick callback
  spin1_set_timer_tick( 1000 ); // Timer tick / us
  spin1_callback_on( TIMER_TICK, timer_callback, 0 );

  // Broadcast sent packets to every core
  spin1_set_mc_table_entry( 0, 0x00000010, 0xffffffff, 0x00000100 );

  // Go!
  spin1_start( );
}

void timer_callback( uint simulation_time, uint none )
{
  // Set some predefined values per dimension
  spin1_send_mc_packet( 0x00000010, bitsk( val ), WITH_PAYLOAD );
}

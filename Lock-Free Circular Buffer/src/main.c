#include <stdio.h>
#include "circular_buffer.h"

int main()
{
    CircularBuffer cb;
    cb_init(&cb);

    printf("Writing data...\n");

    for(int i = 0; i < 10; i++)
    {
        if(cb_push(&cb, i))
            printf("Pushed %d\n", i);
        else
            printf("Buffer full! Data %d dropped\n", i);
    }

    printf("\nReading data...\n");

    uint8_t data;

    while(cb_pop(&cb, &data))
    {
        printf("Popped %d\n", data);
    }

    printf("\nOverruns: %u\n", cb.overrun);

    return 0;
}
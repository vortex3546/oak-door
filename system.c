#include <stdio.h>
#include <stdlib.h>
#include <coreinit/screen.h>
#include <coreinit/thread.h>
#include <whb/proc.h>

int main(int argc, char **argv) {
    // Initialize the screen
    OSScreenInit();
    // Set the buffer for the TV
    int tv_buf_size = OSScreenGetBufferSizeEx(SCREEN_TV);
    void *tvBuffer = MEMAllocFromDefaultHeap(tv_buf_size);
    OSScreenSetBufferEx(SCREEN_TV, tvBuffer);

    // Set the buffer for the GamePad
    int drc_buf_size = OSScreenGetBufferSizeEx(SCREEN_DRC);
    void *drcBuffer = MEMAllocFromDefaultHeap(drc_buf_size);
    OSScreenSetBufferEx(SCREEN_DRC, drcBuffer);

    // Clear both screens
    OSScreenClearBufferEx(SCREEN_TV, 0x00000000);
    OSScreenClearBufferEx(SCREEN_DRC, 0x00000000);

    // Print "Hello, World!" to both screens
    OSScreenPutFontEx(SCREEN_TV, 0, 0, "Hello, World!");
    OSScreenPutFontEx(SCREEN_DRC, 0, 0, "Hello, World!");

    // Flip buffers
    OSScreenFlipBuffersEx(SCREEN_TV);
    OSScreenFlipBuffersEx(SCREEN_DRC);

    // Wait for a few seconds before exiting
    OSSleepTicks(OSSecondsToTicks(5));

    // Free buffers
    MEMFreeToDefaultHeap(tvBuffer);
    MEMFreeToDefaultHeap(drcBuffer);

    return 0;
}

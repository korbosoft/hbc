#include <stdbool.h>
#include <ogc/ios.h>
#include <stdbool.h>
#include <gctypes.h>
#include <ogc/ipc.h>
#include <ogcsys.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "title.h"
// can remove some of those includes i think

static const char* devDolphin [[gnu::aligned(0x20)]] = "/dev/dolphin";
static int dolphin_fd = ~0;
char* unknown_wii_model_message = "Unknown model";

// thanks Naim2000/thepikachugamer for this method of detecting dolphin
bool is_dolphin() {
	if (!~dolphin_fd) {
		dolphin_fd = IOS_Open(devDolphin, 0);
		if (dolphin_fd > 0)
			IOS_Close(dolphin_fd);
	}
	return dolphin_fd > 0;
}

// maybe use an enum later?  needs revamp, wii family edition detection
char* get_wii_model()
{
    if (is_dolphin())
    {
        return "Dolphin";
    }

    if (is_vwii())
    {
        return "Wii U";
    }

    return "Wii";
}
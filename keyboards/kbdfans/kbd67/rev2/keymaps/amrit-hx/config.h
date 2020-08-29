#pragma once

#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION

#define MANUFACTURER    Potato Inc.
#define PRODUCT         Qt3.14
#define DESCRIPTION     KBD67 Rev 2 ISO Layout

/* send tap key if no layer key was used even after tap delay */
#define TAPPING_TERM 200
#define RETRO_TAPPING

/* turn off RGB when computer sleeps */
#ifdef RGB_DI_PIN
#define RGBLIGHT_SLEEP
#endif
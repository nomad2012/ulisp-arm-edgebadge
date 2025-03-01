/*
 User Extensions
*/
  
// Definitions
object *fn_setpixelcolor (object *args, object *env) {
  (void) env;
  int nargs = listlength(args);

  // Set time
  if (nargs == 4) {
    int pixel_num = checkinteger(first(args));
    int r = checkinteger(second(args));
    int g = checkinteger(third(args));
    int b = checkinteger(fourth(args));
    neopixels.setPixelColor(pixel_num, r, g, b);
    neopixels.show();
    return nil;
  } else error2(PSTR("wrong number of arguments"));
  return nil;  
}

/*
object *fn_flushdisplay (object *args, object *env) {
  (void) env;
  #if defined(gfxsupport)
  tft.display();
  #else
  (void) args;
  #endif
  return nil;
}
*/

// Symbol names
const char stringsetpixelcolor[] PROGMEM = "set-neopixel-color";
//const char stringflushdisplay[] PROGMEM = "flush-display";

// Documentation strings
const char docsetpixelcolor[] PROGMEM = "(set-neopixel-color n r g b)\n"
  "Sets neopixel n to color r g b (0-255 each).";
//const char docflushdisplay[] PROGMEM = "(flush-display)\n"
//  "Flushes changes to the graphics display.";

// Symbol lookup table
const tbl_entry_t lookup_table2[] PROGMEM = {
  { stringsetpixelcolor, fn_setpixelcolor, 0244, docsetpixelcolor },
//  { stringflushdisplay, fn_flushdisplay, 0200, docflushdisplay },
};

// Table cross-reference functions

tbl_entry_t *tables[] = {lookup_table, lookup_table2};
const unsigned int tablesizes[] = { arraysize(lookup_table), arraysize(lookup_table2) };

const tbl_entry_t *table (int n) {
  return tables[n];
}

unsigned int tablesize (int n) {
  return tablesizes[n];
}

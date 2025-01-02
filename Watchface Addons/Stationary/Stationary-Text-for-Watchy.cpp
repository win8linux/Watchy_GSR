#include "StationaryText.h" // watchface header file
        
WatchyGSR watchyGSR;

class WatchFace : public WatchyGSR { //inherit and extend WatchyGSR class
  public:
    void drawWatchFace() { //override this method to customize how the watch face looks
      uint16_t lines = 0;
      const char *lows [10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
      const char *teensone [11] = {"","ten", "eleven", "twelve", "thir", "four", "fif", "six", "seven", "eight", "nine"};
      const char *teenstwo [11] = {"", "","", "teen", "teen", "teen", "teen", "teen", "teen", "teen", "teen"};
      const char *tens [10] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

      //drawbg
      WatchyGSR::display.fillScreen(watchyGSR.BackColor());
      WatchyGSR::display.setTextColor(watchyGSR.ForeColor());
      WatchyGSR::display.setTextWrap(false);

      //drawtime
      lines += 1;
      WatchyGSR::display.setCursor(8, lines*47-5);
      WatchyGSR::display.setFont(&NunitoSans_Bold28pt7b);
      if (WatchTime.Local.Hour == 0) {
        WatchyGSR::display.print(tens[2]);
        lines += 1;
        WatchyGSR::display.setCursor(8, lines*47-5);
        WatchyGSR::display.print(lows[4]);
      } else if (WatchTime.Local.Hour < 10) {
        WatchyGSR::display.print(lows[WatchTime.Local.Hour]);
      } else if (WatchTime.Local.Hour < 20) {
        WatchyGSR::display.print(teensone[WatchTime.Local.Hour-9]);
        if (WatchTime.Local.Hour > 12) {
          lines += 1;
          WatchyGSR::display.setCursor(8, lines*47-5);
          WatchyGSR::display.print(teenstwo[WatchTime.Local.Hour%10]);
        }
      } else {
        WatchyGSR::display.print(tens[WatchTime.Local.Hour/10]);
        if (WatchTime.Local.Hour%10 > 0) {
          lines += 1;
          WatchyGSR::display.setCursor(8, lines*47-5);
          WatchyGSR::display.print(lows[WatchTime.Local.Hour%10]);
        }
      }

      lines += 1;
      WatchyGSR::display.setCursor(8, lines*47-5);
      WatchyGSR::display.setFont(&NunitoSans_Light28pt7b);
      if (WatchTime.Local.Minute == 0) {
        WatchyGSR::display.print("o'clock");
      } else if (WatchTime.Local.Minute < 10) {
          WatchyGSR::display.print("oh");
          lines += 1;
          WatchyGSR::display.setCursor(8, lines*47-5);
          WatchyGSR::display.print(lows[WatchTime.Local.Minute]);
      } else if (WatchTime.Local.Minute < 20) {
        WatchyGSR::display.print(teensone[WatchTime.Local.Minute-9]);
        if (WatchTime.Local.Minute > 12) {
          lines += 1;
          WatchyGSR::display.setCursor(8, lines*47-5);
          WatchyGSR::display.print(teenstwo[WatchTime.Local.Minute%10]);
        }
      } else {
        WatchyGSR::display.println(tens[WatchTime.Local.Minute/10]);
        if (WatchTime.Local.Minute%10 > 0) {
          lines += 1;
          WatchyGSR::display.setCursor(8, lines*47-5);
          WatchyGSR::display.print(lows[WatchTime.Local.Minute%10]);
        }
      }                
    }
};

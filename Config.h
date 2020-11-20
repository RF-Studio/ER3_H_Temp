

// FSEC 
#pragma config BWRP = OFF               // Boot Segment Write-Protect bit (Boot Segment may be written) 
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP)) 
#pragma config BSEN = OFF               // Boot Segment Control bit (No Boot Segment) 
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written) 
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP)) 
#pragma config CWRP = OFF               // Configuration Segment Write-Protect bit (Configuration Segment may be written) 
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP)) 
#pragma config AIVTDIS = OFF            // Alternate Interrupt Vector Table bit (Disabled AIVT)

// FBSLIM 
#pragma config BSLIM = 0x1FFF           // Boot Segment Flash Page Address Limit bits (Enter Hexadecimal value)

// FOSCSEL 
#pragma config FNOSC = FRC              // Oscillator Source Selection (Internal Fast RC (FRC)) 
#pragma config PLLMODE = DISABLED       // PLL Mode Selection (No PLL used; PLLEN bit is not available) 
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FOSC 
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled) 
#pragma config OSCIOFCN = ON            // OSC2 Pin Function bit (OSC2 is general purpose digital I/O pin) 
#pragma config SOSCSEL = ON             // SOSC Power Selection Configuration bits (SOSC is used in crystal (SOSCI/SOSCO) mode) 
#pragma config PLLSS = PLL_FRC          // PLL Secondary Selection Configuration bit (PLL is fed by the on-chip Fast RC (FRC) oscillator) 
#pragma config IOL1WAY = OFF            // Peripheral pin select configuration bit (Allow multiple reconfigurations) 
#pragma config FCKSM = CSECMD           // Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled)

// FWDT 
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler bits (1:32,768) 
#pragma config FWPSA = PR128            // Watchdog Timer Prescaler bit (1:128) 
#pragma config FWDTEN = OFF             // Watchdog Timer Enable bits (WDT and SWDTEN disabled) 
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode) 
#pragma config WDTWIN = WIN75           // Watchdog Timer Window Select bits (WDT Windo is 75% of WDT period) 
#pragma config WDTCMX = WDTCLK          // WDT MUX Source Select bits (WDT clock source is determined by the WDTCLK Configuration bits) 
#pragma config WDTCLK = LPRC            // WDT Clock Source Select bits (WDT uses LPRC)

// FPOR 
#pragma config BOREN = NO_SLEEP         // Brown Out Enable bit (Disabled for Sleep Modes) 
#pragma config LPCFG = ON               // Low power regulator control (Retention Sleep controlled by RETEN) 
#pragma config DNVPEN = DISABLE         // Downside Voltage Protection Enable bit (Downside protection disabled when BOR is inactive)

// FICD 
#pragma config ICS = PGD1               // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1) 
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)

// FDEVOPT1 
#pragma config ALTCMPI = DISABLE        // Alternate Comparator Input Enable bit (C1INC, C2INC, and C3INC are on their standard pin locations) 
#pragma config TMPRPIN = OFF            // Tamper Pin Enable bit (TMPRN pin function is disabled) 
#pragma config SOSCHP = OFF             // SOSC High Power Enable bit (valid only when SOSCSEL = 1 (Enable SOSC low power mode) 
#pragma config ALTI2C1 = ALTI2CEN       // Alternate I2C pin Location (SDA1 and SCL1 on RB9 and RB8)

#include <stdio.h>          // pour le printf
#include <libpic30.h>       // pour utiliser la macro __C30_UARTavec le printf

/*-----------------------------------------------------------------------------
Cette librairie doit etre utilisée avec le PIC24FJ256GA702
dans le cadre de la mesure de temperature
sur une carte avec economie d'energie
-----------------------------------------------------------------------------*/


// A utiliser pour toute variable On_Off des fonctions ci-dessous
#define ON                          1
#define OFF                         0


// A utiliser avec la variable : unsigned char ADC_Anx de la fonction  Lib_Temp_ADC_Config_ANx
#define ADC_AN0_RA0_BORNE_2         26
#define ADC_AN1_RA1_BORNE_3         27
#define ADC_AN2_RB0_BORNE_4         0
#define ADC_AN3_RB1_BORNE_5         1
#define ADC_AN4_RB2_BORNE_6         2
#define ADC_AN5_RB3_BORNE_7         3
#define ADC_AN6_RB14_BORNE_25       14
#define ADC_AN7_RB13_BORNE_24       13
#define ADC_AN8_RB12_BORNE_23       12
#define ADC_AN9_RB15_BORNE_26       15



#define BIT_RA0        26
#define BIT_RA1        27
#define BIT_RA2        28
#define BIT_RA3        29
#define BIT_RA4        30
#define BIT_RB0        0
#define BIT_RB1        1
#define BIT_RB2        2
#define BIT_RB3        3
#define BIT_RB4        4
#define BIT_RB5        5
#define BIT_RB6        6
#define BIT_RB7        7
#define BIT_RB8        8
#define BIT_RB9        9
#define BIT_RB10       10
#define BIT_RB11       11
#define BIT_RB12       12
#define BIT_RB13       13
#define BIT_RB14       14
#define BIT_RB15       15



// A utiliser avec la variable unsigned char CPU_Low_Power_Mode de la fonction Lib_Temp_CPU_Gestion_Low_Power_Sleep_Mode
#define CPU_LOW_POWER_MODE_FAST_WAKE_UP         0       // Conso quelques µA
#define CPU_LOW_POWER_MODE_SLEEP                1       // Conso autour de 100 µA
#define CPU_LOW_POWER_MODE_FAST_RETENTION       2       // Conso moins de 1 µA
#define CPU_LOW_POWER_MODE_RETENTION_SLEEP      3       // Conso environ 1 µA



// A utiliser avec le type de variable MRF89_DEFINE_PORT de la librairie du MRF89
#define MRF89_BIT_RA0        26
#define MRF89_BIT_RA1        27
#define MRF89_BIT_RA2        28
#define MRF89_BIT_RA3        29
#define MRF89_BIT_RA4        30
#define MRF89_BIT_RB0        0
#define MRF89_BIT_RB1        1
#define MRF89_BIT_RB2        2
#define MRF89_BIT_RB3        3
#define MRF89_BIT_RB4        4
#define MRF89_BIT_RB5        5
#define MRF89_BIT_RB6        6
#define MRF89_BIT_RB7        7
#define MRF89_BIT_RB8        8
#define MRF89_BIT_RB9        9
#define MRF89_BIT_RB10       10
#define MRF89_BIT_RB11       11
#define MRF89_BIT_RB12       12
#define MRF89_BIT_RB13       13
#define MRF89_BIT_RB14       14
#define MRF89_BIT_RB15       15



// Liste des registres de onfiguration du MRF89
#define MRF89_GCONREG                   0
#define MRF89_DMODREG                   1
#define MRF89_FDEVREG                   2
#define MRF89_BRSREG                    3
#define MRF89_FLTHREG                   4
#define MRF89_FIFOCREG                  5
#define MRF89_R1CREG                    6
#define MRF89_P1CREG                    7
#define MRF89_S1CREG                    8
#define MRF89_R2CREG                    9
#define MRF89_P2CREG                    10
#define MRF89_S2CREG                    11
#define MRF89_PACREG                    12
#define MRF89_FTXRXIREG                 13
#define MRF89_FTPRIREG                  14
#define MRF89_RSTHIREG                  15
#define MRF89_FILCREG                   16
#define MRF89_PFCREG                    17
#define MRF89_SYNCREG                   18
#define MRF89_RESVREG                   19
#define MRF89_RSTSREG                   20
#define MRF89_OOKCREG                   21
#define MRF89_SYNCV31REG                22
#define MRF89_SYNCV23REG                23
#define MRF89_SYNCV15REG                24
#define MRF89_SYNCV07REG                25
#define MRF89_TXCONREG                  26
#define MRF89_CLKOUTREG                 27
#define MRF89_PLOADREG                  28
#define MRF89_NADDSREG                  29
#define MRF89_PKTCREG                   30
#define MRF89_FCRCREG                   31

// A utiliser avec la fonction : Lib_Temp_MRF89_Change_Mode du MRF89
#define MRF89_MODE_SLEEP                0
#define MRF89_MODE_STAND_BY             1
#define MRF89_MODE_SYNTHESIZER          2
#define MRF89_MODE_RECEIVE              3
#define MRF89_MODE_TRANSMIT             4


// A utiliser avec la fonction : Lib_Temp_MRF89_Change_Taille_FIFO du MRF89
#define MRF89_TAILLE_FIFO_16_OCTETS     0
#define MRF89_TAILLE_FIFO_32_OCTETS     1
#define MRF89_TAILLE_FIFO_48_OCTETS     2
#define MRF89_TAILLE_FIFO_64_OCTETS     3



// A utiliser avece les variables unsigned char Nom_Signal_In de la fonction Lib_Temp_REMAP_RPx_IN
#define REMAP_SIGNAL_IN_OCTRIG1  0
#define REMAP_SIGNAL_IN_INT1     1
#define REMAP_SIGNAL_IN_INT2     2
#define REMAP_SIGNAL_IN_INT3     3
#define REMAP_SIGNAL_IN_INT4     4
#define REMAP_SIGNAL_IN_OCTRIG2  5
#define REMAP_SIGNAL_IN_T2CK     6
#define REMAP_SIGNAL_IN_T3CK     7
#define REMAP_SIGNAL_IN_ICM1     8
#define REMAP_SIGNAL_IN_ICM2     9
#define REMAP_SIGNAL_IN_ICM3     10
#define REMAP_SIGNAL_IN_ICM4     11
#define REMAP_SIGNAL_IN_IC1      12
#define REMAP_SIGNAL_IN_IC2      13
#define REMAP_SIGNAL_IN_IC3      14
#define REMAP_SIGNAL_IN_OCFA     15
#define REMAP_SIGNAL_IN_OCFB     16
#define REMAP_SIGNAL_IN_TCKIA    17
#define REMAP_SIGNAL_IN_TCKIB    18
#define REMAP_SIGNAL_IN_U1RX     19
#define REMAP_SIGNAL_IN_U1CTS    20
#define REMAP_SIGNAL_IN_U2RX     21
#define REMAP_SIGNAL_IN_U2CTS    22
#define REMAP_SIGNAL_IN_SDI1     23
#define REMAP_SIGNAL_IN_SCK1IN   24
#define REMAP_SIGNAL_IN_SS1IN    25
#define REMAP_SIGNAL_IN_SDI2     26
#define REMAP_SIGNAL_IN_SCK2IN   27
#define REMAP_SIGNAL_IN_SS2IN    28
#define REMAP_SIGNAL_IN_TxCK     29
#define REMAP_SIGNAL_IN_CLCINA   30
#define REMAP_SIGNAL_IN_CLCINB   31
#define REMAP_SIGNAL_IN_SDI3     32
#define REMAP_SIGNAL_IN_SCK3IN   33
#define REMAP_SIGNAL_IN_SS3IN    34


//A utiliser avece les variables unsigned char Nom_Signal_Out de la fonction Lib_Temp_REMAP_RPx_OUT
#define REMAP_SIGNAL_OUT_Aucun     0
#define REMAP_SIGNAL_OUT_C1OUT     1
#define REMAP_SIGNAL_OUT_C2OUT     2
#define REMAP_SIGNAL_OUT_U1TX      3
#define REMAP_SIGNAL_OUT_U1RTS     4
#define REMAP_SIGNAL_OUT_U2TX      5
#define REMAP_SIGNAL_OUT_U2RTS     6
#define REMAP_SIGNAL_OUT_SDO1      7
#define REMAP_SIGNAL_OUT_SCK1OUT   8
#define REMAP_SIGNAL_OUT_SS1OUT    9
#define REMAP_SIGNAL_OUT_SDO2      10
#define REMAP_SIGNAL_OUT_SCK2OUT   11
#define REMAP_SIGNAL_OUT_SS2OUT    12
#define REMAP_SIGNAL_OUT_OC1       13
#define REMAP_SIGNAL_OUT_OC2       14
#define REMAP_SIGNAL_OUT_OC3       15
#define REMAP_SIGNAL_OUT_OCM2A     16
#define REMAP_SIGNAL_OUT_OCM2B     17
#define REMAP_SIGNAL_OUT_OCM3A     18
#define REMAP_SIGNAL_OUT_OCM3B     19
#define REMAP_SIGNAL_OUT_OCM4A     20
#define REMAP_SIGNAL_OUT_OCM4B     21
#define REMAP_SIGNAL_OUT_SDO3      23
#define REMAP_SIGNAL_OUT_SCK3OUT   24
#define REMAP_SIGNAL_OUT_SS3OUT    25
#define REMAP_SIGNAL_OUT_C3OUT     26
#define REMAP_SIGNAL_OUT_PWRGT     27
#define REMAP_SIGNAL_OUT_REFO      28
#define REMAP_SIGNAL_OUT_CLC1OUT   29
#define REMAP_SIGNAL_OUT_CLC2OUT   30
#define REMAP_SIGNAL_OUT_RTCC      31


// A utiliser avec les fonctions : Lib_Temp_REMAP_RPx_IN et Lib_Temp_REMAP_RPx_OUT
#define RP0_RB0_BORNE_4         0
#define RP1_RB1_BORNE_5         1
#define RP2_RB2_BORNE_6         2
#define RP3_RB3_BORNE_7         3
#define RP4_RB4_BORNE_11        4
#define RP5_RB5_BORNE_14        5
#define RP6_RB6_BORNE_15        6
#define RP7_RB7_BORNE_16        7
#define RP8_RB8_BORNE_17        8
#define RP9_RB9_BORNE_18        9
#define RP10_RB10_BORNE_21      10
#define RP11_RB11_BORNE_22      11
#define RP12_RB12_BORNE_23      12
#define RP13_RB13_BORNE_24      13
#define RP14_RB14_BORNE_25      14
#define RP15_RB15_BORNE_26      15
#define RP26_RA0_BORNE_2        26
#define RP27_RA1_BORNE_3        27





// A utiliser avec la fonction : Lib_Temp_ADC_Config_ANx
typedef struct
{
    unsigned char   Bit_Voie_de_Conversion_ADC_ANx;             /*ADC_AN0_RA0_BORNE_2 à ADC_AN9_RB15_BORNE_26*/
    unsigned char   Bit_Alimentation_Capteur_Temperature;       /*BIT_RA0 à BIT_RB15*/
    unsigned char   Autorise_Interruption;                      /*0:non autorisé  -  1:autorisé*/
    unsigned char   Niveau_Priorite;                            /*Niveau de 0 à 7*/
}ADC_CONFIG;





// A utiliser avec les fonctions du MRF89 pour changer le débit de transmission
typedef enum _DEBIT   { DEBIT_187500_BITS_PAR_SECONDE = 0, DEBIT_93750_BITS_PAR_SECONDE,
                        DEBIT_62500_BITS_PAR_SECONDE, DEBIT_46880_BITS_PAR_SECONDE,
                        DEBIT_37500_BITS_PAR_SECONDE, DEBIT_31250_BITS_PAR_SECONDE
                        } MRF89_DEBIT;

// A utiliser avec les fonctions du MRF89
typedef enum _PASFILV   { FILTER_65_KHZ = 0, FILTER_82_KHZ, FILTER_109_KHZ, FILTER_137_KHZ,
                        FILTER_157_KHZ , FILTER_184_KHZ, FILTER_211_KHZ, FILTER_234_KHZ,
                        FILTER_262_KHZ , FILTER_321_KHZ, FILTER_378_KHZ, FILTER_414_KHZ,
                        FILTER_458_KHZ , FILTER_514_KHZ, FILTER_676_KHZ, FILTER_987_KHZ 
                        } MRF89_PASFILV;

// A utiliser avec les fonctions du MRF89
typedef enum _BUTTERWORTH   { BUT_Fc_Fo_25_KHZ = 0, BUT_Fc_Fo_50_KHZ, BUT_Fc_Fo_75_KHZ, BUT_Fc_Fo_100_KHZ,
                            BUT_Fc_Fo_125_KHZ, BUT_Fc_Fo_150_KHZ, BUT_Fc_Fo_175_KHZ, BUT_Fc_Fo_200_KHZ,
                            BUT_Fc_Fo_225_KHZ, BUT_Fc_Fo_250_KHZ, BUT_Fc_Fo_275_KHZ, BUT_Fc_Fo_300_KHZ,
                            BUT_Fc_Fo_325_KHZ, BUT_Fc_Fo_350_KHZ, BUT_Fc_Fo_375_KHZ, BUT_Fc_Fo_400_KHZ
                            } MRF89_BUTTERWORTH;

// A utiliser avec les fonctions du MRF89
typedef enum _TXOPVAL { TXOPVAL_13_DBM = 0, TXOPVAL_10_DBM, TXOPVAL_7_DBM, TXOPVAL_4_DBM,
                        TXOPVAL_1_DBM , TXOPVAL_MOINS_2_DBM, TXOPVAL_MOINS_5_DBM, TXOPVAL_MOINS_8_DBM } TXOPVAL;


// A utiliser avec les fonctions du MRF89
typedef struct
{
    unsigned char               BIT_CSCON;      /*MRF89_BIT_RA0 à MRF89_BIT_RB15*/
    unsigned char               BIT_CSDATA;     /*MRF89_BIT_RA0 à MRF89_BIT_RB15*/
    unsigned char               BIT_RESET;      /*MRF89_BIT_RA0 à MRF89_BIT_RB15*/
    unsigned char               BIT_IRQ0;       /*MRF89_BIT_RA0 à MRF89_BIT_RB15*/
    unsigned char               BIT_IRQ1;       /*MRF89_BIT_RA0 à MRF89_BIT_RB15*/
}MRF89_DEFINE_PORT;


// A utiliser avec la fonction : Lib_Temp_PORT_Config_IOC
typedef struct
{
    unsigned char               BIT_RPx;                        /*BIT_RA0 à BIT_RB15*/
    unsigned char               Actif_sur_Front_Montant;        /*0:non actif   -   1:actif*/
    unsigned char               Actif_sur_Front_Deccendant;     /*0:non actif   -   1:actif*/
    unsigned char               Autorise_Interruption;          /*0:non autorisé  -  1:autorisé*/
    unsigned char               Niveau_Priorite;                /*Niveau de 0 à 7*/
}PORT_IOC;



// A utiliser avec les fonctions du RTCC
typedef struct
{
    union
    {
        unsigned int Min_Sec;
        struct
        {
            unsigned char Second;
            unsigned char Minute;
        };
    };
    union
    {
        unsigned int JourSem_Heure;
        struct
        {
            unsigned char Heure;
            unsigned char JourSemaine;      // 0 pour Dimanche
        };
    };
    union
    {
        unsigned int Mois_Jour;
        struct
        {
            unsigned char Jour;
            unsigned char Mois;
        };
    };

    union
    {
        unsigned int PowerControl;
        struct
        {
            unsigned char PWCSAMP;
            unsigned char PWCSTAB;
        };
        unsigned int Annee;
        struct
        {
            unsigned char An;
            unsigned char  : 8;
        };
    };
} RTCC_DATE;


// A utiliser avec les fonctions du RTCC
typedef struct
{
    unsigned char   Jour_Sem;
    unsigned char   Sec_ten;
    unsigned char   Sec_unit;
    unsigned char   Min_ten;
    unsigned char   Min_unit;
    unsigned char   Heure_ten;
    unsigned char   Heure_unit;
    unsigned char   Jour_ten;
    unsigned char   Jour_unit;
    unsigned char   Mois_ten;
    unsigned char   Mois_unit;
    unsigned char   An_ten;
    unsigned char   An_unit;
} RTCC_DATE_BRUT;





void Lib_Temp_ADC_Activation_Alim(unsigned char On_Off);
void Lib_Temp_ADC_Alimente_Capteur_Temperature(unsigned char On_Off);
void Lib_Temp_ADC_Config_ANx(ADC_CONFIG Config_ADC);        // Configure l'ADC pour convertir 16 ùesure sur la voie ADC_ANx
void Lib_Temp_ADC_Activation_Interruption(unsigned char On_Off, unsigned char Niveau_Priorite);
void Lib_Temp_ADC_Start_Conversion_Automatique(void);
void Lib_Temp_ADC_Stop_Conversion_Automatique(void);
char Lib_Temp_ADC_Attend_Fin_Conversion(void);          // retourne 1 si fin de conversion correcte sinon retourne -1 si probleme
unsigned int Lib_Temp_ADC_Resultat_Conversion_Somme_des_8_derniers_Echantillons(void);  // retourne la somme des 8 derniers buffers de conversions
unsigned int Lib_Temp_ADC_Temperature_en_Centieme_de_degre(unsigned int V_Alim_en_mV);  // retourne les 8 derniers buffers de conversions en temperature



void Lib_Temp_CPU_Alimentation_Tous_Les_Modules(unsigned char On_Off);
void Lib_Temp_CPU_Gestion_Low_Power_Sleep_Mode(unsigned char CPU_Low_Power_Mode);       // #pragma config LPCFG = ON    // Low power regulator control (Retention Sleep controlled by RETEN)
void Lib_Temp_CPU_Activation_Interruption(unsigned char On_Off, unsigned char Niveau_Priorite);


    
char Lib_Temp_MRF89_Config(MRF89_DEFINE_PORT Config_Port);      // config defaut : 93.75 kbits par seconde - P_out = 13 dBm

void Lib_Temp_MRF89_Write_SPI_Config_Register(unsigned char Registre, unsigned char Value);
unsigned char Lib_Temp_MRF89_Read_SPI_Config_Register(unsigned char Registre);

void Lib_Temp_MRF89_Ecriture_SPI_FIFO(unsigned char Adr_MRF_Distant, unsigned char *Data);
char Lib_Temp_MRF89_Attend_Fin_Transmission_Hertzienne(void);       // Renvoie 1 si tout s'est bien passé sinon -1

void Lib_Temp_MRF89_Change_Mode(unsigned char Mode);
char Lib_Temp_MRF89_Change_Canal(unsigned char Canal);
unsigned char Lib_Temp_MRF89_Change_Taille_FIFO(unsigned char enum_MRF89_TAILLE_FIFO);
void Lib_Temp_MRF89_Change_Debit_Transmission(unsigned char enum_MRF89_DEBIT);
void Lib_Temp_MRF89_Change_Puissance_de_Sortie(unsigned char enum_MRF89_TXOPVAL);

double Lib_Temp_MRF89_Lecture_Frequence_du_Canal_MHz(void);
unsigned char Lib_Temp_MRF89_Lecture_Taille_FIFO_en_Octet(void);
unsigned char Lib_Temp_MRF89_Lecture_Mode(void);
char Lib_Temp_MRF89_Lecture_Puissance_de_Sortie_en_dBm(void);
unsigned long Lib_Temp_MRF89_Lecture_Debit_transmission_en_Hertz(void);



void Lib_Temp_PORT_Init_Tous_En_Entree_ANALOGIUE(void);
void Lib_Temp_PORT_Init_Tous_En_Entree_NUMERIQUE(void);
void Lib_Temp_PORT_Init_Tous_En_Sortie_Numerique_A_Etat_BAS(void);
void Lib_Temp_PORT_Init_Tous_En_Sortie_Numerique_A_Etat_HAUT(void);
void Lib_Temp_PORT_Config_IOC(PORT_IOC Config_Port_IOC);



void Lib_Temp_REMAP_RPx_IN(unsigned char Nom_Signal_In, unsigned char Numero_RP);
void Lib_Temp_REMAP_RPx_OUT(unsigned char Nom_Signal_Out, unsigned char Numero_RP);



void Lib_Temp_RTCC_Config(void);
void Lib_Temp_RTCC_Ecriture_Date_Dans_Module_RTCC_du_Microcontroleur(RTCC_DATE Date);
void Lib_Temp_RTCC_Lecture_Date(RTCC_DATE *Date);
void Lib_Temp_RTCC_Lecture_Date_Brut(RTCC_DATE_BRUT *Date_Brut);
void Lib_Temp_RTCC_Activation_Clock_Out(unsigned char On_Off);
void Lib_Temp_RTCC_Activation_Interruption(unsigned char On_Off, unsigned char Niveau_Priorite);
void Lib_Temp_RTCC_Conversion_Date_En_Seconde(RTCC_DATE Date, unsigned long *Sec);
void Lib_Temp_RTCC_Conversion_Seconde_En_Date(unsigned long Sec, RTCC_DATE *Date);
void Lib_Temp_RTCC_Conversion_Seconde_en_Date_String(unsigned long Date_seconde, char *s);






void Lib_Temp_SPI_Activation_Alim(unsigned char On_Off);
void Lib_Temp_SPI_Config(unsigned char Num_SPI);                // Numero SPI de 1 à 3
unsigned char Lib_Temp_SPI_Read_Write(unsigned char Data);




void Lib_Temp_UART_Activation_Alim(unsigned char On_Off);
void Lib_Temp_UART_Config(unsigned char Numero_UART, float Fcyc, float Vitesse_en_Baud);
float Lib_Temp_UART_Vitesse_de_Transmission(float Fcyc, float Vitesse_en_Baud);
void Lib_Temp_UART_Activation_Interruption_RX(unsigned char On_Off, unsigned char Niveau_Priorite);
void Lib_Temp_UART_Activation_Interruption_TX(unsigned char On_Off, unsigned char Niveau_Priorite);




/*

//------------------------------------------------------------------------------
// Interruption de l'ADC1
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _ADC1Interrupt(void)
{
    
    
    AD1CON1bits.ASAM        = 0;            // Stop auto conversion
    IFS0bits.AD1IF          = 0;
}
//------------------------------------------------------------------------------





//------------------------------------------------------------------------------
// Interruption IOC (Interrupt On Change)
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _IOCInterrupt(void)
{
    
    
    IOCFB                   = 0;
    IOCSTAT                 = 0;
    IFS1bits.IOCIF          = 0;
}
//------------------------------------------------------------------------------





//------------------------------------------------------------------------------
// Interruption U1RX - Reception UART 1
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _U1RXInterrupt(void)
{

    IFS0bits.U1RXIF                 = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Interruption U1TX - Emission UART 1
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _U1TXInterrupt(void)
{
    
    IFS0bits.U1TXIF             = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Interruption U2RX - Reception UART 2
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _U2RXInterrupt(void)
{

    IFS1bits.U2RXIF                 = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Interruption U2TX - Emission UART 2
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _U2TXInterrupt(void)
{

    IFS1bits.U2TXIF                 = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Interruption RTCC
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _RTCCInterrupt(void)
{
    
    RTCCON1Hbits.ALRMEN         = 1;
    IFS3bits.RTCIF              = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Interruption SPI TX
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _SPI1TXInterrupt(void)
{
    
    IFS0bits.SPI1TXIF       = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Interruption SPI RX
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _SPI1RXInterrupt(void)
{
    
    IFS3bits.SPI1RXIF       = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Interruption SPI TX
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _SPI2TXInterrupt(void)
{
    
    IFS2bits.SPI2TXIF       = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Interruption SPI RX
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _SPI2RXInterrupt(void)
{
    
    IFS3bits.SPI2RXIF       = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Interruption SPI TX
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _SPI3TXInterrupt(void)
{
    
    IFS5bits.SPI3TXIF       = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Interruption SPI RX
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _SPI3RXInterrupt(void)
{
    
    IFS3bits.SPI3RXIF       = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------




*/









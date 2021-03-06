#pragma once
#include "GMidi.h"

class CGenCF1 :
	public CGMidi
{
public:
	CGenCF1();
	~CGenCF1();
	void Generate() override;
	void LoadConfigLine(CString * sN, CString * sV, int idata, double fdata);

protected:
	// Parameters
	int min_interval = 1; // Minimum diatonic interval in cantus (7 = octave)
	int max_interval = 5; // Maximum diatonic interval in cantus (7 = octave)
	int c_len = 9; // Number of measures in each cantus. Usually 9 to 11
	int first_note = 72; // Starting note of each cantus
	int last_diatonic_int = 0; // Diatonic interval between first and last note
	vector <unsigned char> accept; // Each upper case letter allows showing canti with specific properties:
	int fill_steps_mul = 2; // Multiply number of notes between leap notes to get steps for filling
	int max_repeat_mul = 2; // Allow repeat of X notes after at least X*max_repeat_mul steps if beats are different
	int max_smooth_direct = 5; // Maximum linear movement in one direction allowed (in steps)
	int max_smooth = 7; // Maximum linear movement allowed (in steps)
	int max_leaps = 2; // Maximum allowed max_leaps during max_leap_steps
	int max_leaps2 = 3; // Maximum allowed max_leaps2 during max_leap_steps for Many leaps+
	int max_leap_steps = 7;
	int stag_notes = 2; // Maximum allowed stag_notes (same notes) during stag_note_steps
	int stag_note_steps = 7;
	int min_tempo = 110;
	int max_tempo = 120;
	double random_choose = 100; // Percent of accepted canti to show and play
	int calculate_correlation = 0; // Enables correlation calculation algorithm. Slows down generation. Outputs to cf1-cor.csv
};

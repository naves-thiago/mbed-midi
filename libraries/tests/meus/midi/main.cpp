#include "mbed.h"
#include "USBMIDI.h"

AnalogIn pot(p20);
USBMIDI midi;

#define MEAN_COUNT 15

int samples[MEAN_COUNT];
int count = 0;
int oldest = 0;
int last = -1;
int main()
{
//	wait(5);
	while (1)
	{
		float v = pot.read();
		int vi = v * 127;
		int mean;

		if (count < MEAN_COUNT)
		{
			samples[count] = vi;
			count ++;
		}
		else
		{
			mean = 0;
			for (int i=0; i<MEAN_COUNT; i++)
				mean += samples[i];

			mean /= MEAN_COUNT;
			printf("-> %d\n", mean);
			if (mean != last)
			{
				last = mean;
				// Control, Value (0-127), channel
				midi.write(MIDIMessage::ControlChange(1, mean, 0));
			}

			samples[oldest] = vi;
			oldest ++;
			oldest = oldest % MEAN_COUNT;

			wait(0.005);
		}
	}
	return 0;
}

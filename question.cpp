#include "question.h"

using namespace CODE;

Data DataProcess::FindMaximumValue()
{
	// -return max sum + time interval
	// -all values are positive integer
	Data maxData = datum[0];
	int maxSum = dataum[0].value;
	int sum = 0, i = 0, len = datum.Length;
	
	while (i < len - 1)
	{
		int start_idx = i;
		sum = datum[start_idx].value;
		while(i < len - 1 && datum[i+1].start_time < datum[start_idx].end_time)
		{
			sum += datum[i+1].value;
			++i;
		}
		if(sum > maxSum)
		{
			maxSum = sum;
			if( i > start_idx)
				maxData.start_time = datum[i-1].start_time;
			else
				maxData.start_time = datum[start_idx].start_time;
			maxData.end_time = datum[start_idx].end_time;
			maxData.value = sum;
		}
	}//end-while
	if(datum[i].value > maxSum)
	{
		maxSum = datum[i].value;
		maxData = datum[i];
	}
	return maxData;
}

int DataProcess::FindMaximumValue()
{
	// -only return max sum
	// -all values are positive integer
	int maxSum = dataum[0].value;
	int sum = 0, i = 0, len = datum.Length;
	while (i < len - 1)
	{
		int start_idx = i;
		sum = datum[start_idx].value;
		while(i < len - 1 && datum[i+1].start_time < datum[start_idx].end_time)
		{
			sum += datum[i+1].value;
			++i;
		}
		if(sum > maxSum)
		{
			maxSum = sum;
		}
	}//end-while
	if(datum[i].value > maxSum)
		maxSum = datum[i].value;
	return maxSum;
}

int DataProcess::FindMaximumValue()
{
	// -only return max sum
	// -values can be either positive or negative integer
	int maxSum = dataum[0].value;
	int sum = 0, i = 0, len = datum.Length;
	while (i < len - 1)
	{
		int start_idx = i;
		sum = datum[start_idx].value;
		int maxi = sum; 
		
		while(i < len - 1 && datum[i+1].start_time < datum[start_idx].end_time)
		{
			sum += datum[i+1].value;
			if(datum[i+1].value > maxi)
				maxi = datum[i+1].value; // in case negative add
			++i;
		}
		if(sum > maxSum)
			maxSum = sum;
		if(maxi > maxSum)
			maxSum = max;

	}//end-while
	if(datum[i].value > maxSum)
		maxSum = datum[i].value;
	return maxSum;
}
// measurements should be done in the coil conduction cycle
// trigger ADC with overlapping edge (see scope)
// memory for prev power calc prev volt calc, current DutyC, adc meas of input voltage, adc meas of input current during ON cycle, the amount to change the DC with
void mppt(uint32_t *pwr, uint32_t *volt, uint32_t *DutyC, uint32_t *adc_volt, uint32_t *adc_curr, uint32_t delta_DutyC)
{ // trigger this function with the slow timer to not update too often
    uint32_t temp_pwr    = *pwr;
    uint32_t temp_volt   = *volt;
    uint32_t current     = CONV_CONST_I * *adc_volt;
    *volt                = CONV_CONST_V * *adc_curr;
    *pwr                 = voltage * current;
    if((*pwr > temp_pwr))   
    {
        *DutyC = (*volt > temp_volt) ? ++delta_DutyC : --delta_DutyC;
    }
    else
    {
        *DutyC = (*volt > temp_volt) ? --delta_DutyC : ++delta_DutyC;
    }
    return;
}
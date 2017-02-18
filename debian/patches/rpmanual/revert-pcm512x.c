Revert some stylistic changes from later 3.16 kernels that conflict with rpi
patches.
Index: extract/sound/soc/codecs/pcm512x.c
===================================================================
--- extract.orig/sound/soc/codecs/pcm512x.c
+++ extract/sound/soc/codecs/pcm512x.c
@@ -188,8 +188,8 @@ static const DECLARE_TLV_DB_SCALE(boost_
 static const char * const pcm512x_dsp_program_texts[] = {
 	"FIR interpolation with de-emphasis",
 	"Low latency IIR with de-emphasis",
-	"High attenuation with de-emphasis",
 	"Fixed process flow",
+	"High attenuation with de-emphasis",
 	"Ringing-less low latency FIR",
 };
 
@@ -261,9 +261,9 @@ static const struct soc_enum pcm512x_ved
 static const struct snd_kcontrol_new pcm512x_controls[] = {
 SOC_DOUBLE_R_TLV("Playback Digital Volume", PCM512x_DIGITAL_VOLUME_2,
 		 PCM512x_DIGITAL_VOLUME_3, 0, 255, 1, digital_tlv),
-SOC_DOUBLE_TLV("Analogue Playback Volume", PCM512x_ANALOG_GAIN_CTRL,
+SOC_DOUBLE_TLV("Playback Volume", PCM512x_ANALOG_GAIN_CTRL,
 	       PCM512x_LAGN_SHIFT, PCM512x_RAGN_SHIFT, 1, 1, analog_tlv),
-SOC_DOUBLE_TLV("Analogue Playback Boost Volume", PCM512x_ANALOG_GAIN_BOOST,
+SOC_DOUBLE_TLV("Playback Boost Volume", PCM512x_ANALOG_GAIN_BOOST,
 	       PCM512x_AGBL_SHIFT, PCM512x_AGBR_SHIFT, 1, 0, boost_tlv),
 SOC_DOUBLE("Playback Digital Switch", PCM512x_MUTE, PCM512x_RQML_SHIFT,
 	   PCM512x_RQMR_SHIFT, 1, 1),

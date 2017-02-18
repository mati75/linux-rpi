Revert a minor OTG whitelist related change that was conflicting with rpi
patches. The rpf have effectively disabled the OTG whitelist anyway.

Index: extract/drivers/usb/core/otg_whitelist.h
===================================================================
--- extract.orig/drivers/usb/core/otg_whitelist.h
+++ extract/drivers/usb/core/otg_whitelist.h
@@ -59,11 +59,6 @@ static int is_targeted(struct usb_device
 	     le16_to_cpu(dev->descriptor.idProduct) == 0xbadd))
 		return 0;
 
-	/* OTG PET device is always targeted (see OTG 2.0 ECN 6.4.2) */
-	if ((le16_to_cpu(dev->descriptor.idVendor) == 0x1a0a &&
-	     le16_to_cpu(dev->descriptor.idProduct) == 0x0200))
-		return 1;
-
 	/* NOTE: can't use usb_match_id() since interface caches
 	 * aren't set up yet. this is cut/paste from that code.
 	 */

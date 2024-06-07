!function(n){n.su.moduleManager.define("mapRouter",{services:["device","ajax"],models:["lanAdvLanModel","wirelessInfoModel","ipv6NetworkMap","performanceM"],stores:["treeStore"],deps:["navigatorController","index","networkMap"],views:["mapRouterView"],listeners:{"ev_on_launch":function(e,a,o,t,s,i,r){var c=r.device.getCurrentMode();a.isMobileMode="LTE"===c.sysMode||"Mobile_5G"===c.sysMode;var u=r.device.getShowPerformance();"RE"===c.workMode?o.mapRouterView.mapTopology.hide():o.mapRouterView.mapTopology.show(),u?(!function n(){t.performanceM.load({success:function(){setTimeout(n,5e3)},fail:function(){setTimeout(n,5e3)},error:function(){setTimeout(n,5e3)}})}(),o.mapRouterView.performancePanel.show()):o.mapRouterView.performancePanel.hide(),t.lanAdvLanModel.load(),t.wirelessInfoModel.load(),t.ipv6NetworkMap.load()}},init:function(o,t,s,e,i,a){this.listen({"models.wirelessInfoModel":{"ev_loaded":function(e,a){"ON"===a.guest_enable2_4.toUpperCase()?t.mapRouterView.mapRouterGuest.show():!o.isMobileMode||"ON"!==a.guest_enable5_1.toUpperCase()&&"ON"!==a.guest_enable5_2.toUpperCase()?t.mapRouterView.mapRouterGuest.hide():t.mapRouterView.mapRouterGuest.show(),a.is6G?(t.mapRouterView.mapRouter6G.show(),"ON"===a.guest_enable6.toUpperCase()?t.mapRouterView.mapRouterGuest6G.show():t.mapRouterView.mapRouterGuest6G.hide()):t.mapRouterView.mapRouter6G.hide(),i.networkMap.setProductName(),i.index.updateProductName()}},"models.ipv6NetworkMap":{"ev_loaded":function(e,a){a.ip&&s.ipv6NetworkMap.ip.show()}}}),this.control({"#map-router-topo":{"ev_item_click":function(e,a,o,t){this.updateDevicePanel(t),this.updateDeviceName(o),s.lanAdvLanModel.load({data:{device_mac:a}}),s.ipv6NetworkMap.load({data:{device_mac:a}})}}})}},function(t,i,e,s,a,o){return{isMobileMode:!1,initDecoTree:function(e){var a=e.device_list,o=t.list2Tree(a);s.treeStore.loadData(o)},updateDeviceName:function(e){i.mapRouterView.deviceName.setValue(e)},updateDevicePanel:function(e){i.mapRouterView.mapRouterInfo.setTitle(n.su.CHAR.NETWORK_MAP.ROUTER_INFORMATION+"("+e+")")},updateDeviceIMEI:function(e){t.isMobileMode&&i.mapRouterView.IMEINumber.show(),i.mapRouterView.IMEINumber.setValue(e)},setStorage:function(e){var a={PB:n.su.CHAR.UNIT.PB,TB:n.su.CHAR.UNIT.TB,GB:n.su.CHAR.UNIT.GB,MB:n.su.CHAR.UNIT.MB,KB:n.su.CHAR.UNIT.KB,B:n.su.CHAR.UNIT.B};function o(e){return e&&e.toUpperCase()}var t=n.su.capacityToNum(e.storageAvailable+a[o(e.storageAvailableUnit)]),s=n.su.capacityToNum(e.storageCapacity+a[o(e.storageCapacityUnit)]);i.mapRouterView.usbCapacityRate.setValue(t/s*100)},list2Tree:function(e){var a,o,t={},s=n.extend(!0,[],e);e=n.su.filterArrField.call(e,"mac","role","device_model","nickname");for(var i,r=[],c=0;c<e.length;c++)t[(a=e[c]).mac]=c,a.branches=[],a.name=a.device_model,delete a.device_model;for(c=0;c<e.length;c++){switch((i=e[c]).name){case"M1300":case"M5":case"M9Plus":case"P7":o="m5m9plusp7";break;case"M4":case"E4":case"E4R":case"W2400":case"M3":case"E3":case"M4R":case"HC4":case"AC1200":o="M4R";break;case"M3W":o="M3W";break;case"X20":case"HX20":case"X50":case"X60":case"X73":case"W6000":case"W3600":o="X20";break;case"X68":case"X75":case"XE75":case"XE5300":case"X76":case"X80":case"X3600":o="X68";break;case"X90":case"X96":case"X95":case"XE200":case"XE95":case"X5700":case"X80-5G":case"X50-5G":o="X90X5700";break;case"X55":case"X25":o="X25";break;case"X58-4G":o="X58";break;default:o="m5m9plusp7"}i.modelImg=o,"master"!==s[c].role?(u(),e[t[s[c].previous]].branches.push(i)):(u(),r.push(i))}function u(){s[c].online||(i.modelImg=i.modelImg&&i.modelImg+"-offline"||"")}return r}}})}(jQuery);
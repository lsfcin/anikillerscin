#ifndef FACESCHEVETTE_H
#define FACESCHEVETTE_H

#define NUMEROFACESCARRO 180

	const static float modeloCarro[180][3][3] = {
	17.343269f, 1.986084f, 10.0f, 17.843269f, 0.039673f, 10.0f, 22.718269f, 0.048584f, 10.0f,
	17.343269f, 1.986084f, 10.0f, 22.718269f, 0.048584f, 10.0f, 24.218269f, 1.486084f, 10.0f,
	17.343269f, 1.986084f, 10.0f, 24.218269f, 1.486084f, 10.0f, 24.905769f, 3.361084f, 10.0f,
	17.343269f, 1.986084f, 10.0f, 24.905769f, 3.361084f, 10.0f, 24.093269f, 5.111084f, 10.0f,
	17.343269f, 1.986084f, 10.0f, 24.093269f, 5.111084f, 10.0f, 22.182503f, 6.468262f, 10.0f,
	15.843271f, 3.611084f, 10.0f, 17.343269f, 1.986084f, 10.0f, 22.182503f, 6.468262f, 10.0f,
	14.093266f, 3.923584f, 10.0f, 15.843271f, 3.611084f, 10.0f, 22.182503f, 6.468262f, 10.0f,
	14.093266f, 3.923584f, 10.0f, 22.182503f, 6.468262f, 10.0f, 9.916689f, 8.0f, 10.0f,
	12.155764f, 3.423584f, 10.0f, 14.093266f, 3.923584f, 10.0f, 9.916689f, 8.0f, 10.0f,
	10.843264f, 1.986084f, 10.0f, 12.155764f, 3.423584f, 10.0f, 9.916689f, 8.0f, 10.0f,
	10.280764f, 0.048584f, 10.0f, 10.843264f, 1.986084f, 10.0f, 9.916689f, 8.0f, 10.0f,
	10.280764f, 0.048584f, 10.0f, 9.916689f, 8.0f, 10.0f, -10.200012f, 0.0f, 10.0f,
	9.916689f, 8.0f, 10.0f, -10.803162f, 1.825378f, 10.0f, -10.200012f, 0.0f, 10.0f,
	9.916689f, 8.0f, 10.0f, -12.088865f, 3.253967f, 10.0f, -10.803162f, 1.825378f, 10.0f,
	-3.0f, 8.0f, 10.0f, -12.088865f, 3.253967f, 10.0f, 9.916689f, 8.0f, 10.0f,
	-14.088865f, 3.825378f, 10.0f, -12.088865f, 3.253967f, 10.0f, -3.0f, 8.0f, 10.0f,
	-14.088865f, 3.825378f, 10.0f, -3.0f, 8.0f, 10.0f, -17.200012f, 8.0f, 10.0f,
	-15.969849f, 3.373038f, 10.0f, -14.088865f, 3.825378f, 10.0f, -17.200012f, 8.0f, 10.0f,
	-17.231750f, 1.825378f, 10.0f, -15.969849f, 3.373038f, 10.0f, -17.200012f, 8.0f, 10.0f,
	-17.231750f, 1.825378f, 10.0f, -17.200012f, 8.0f, 10.0f, -20.519833f, 7.527771f, 10.0f,
	-20.519833f, 7.527771f, 10.0f, -22.519829f, 3.527771f, 10.0f, -17.231750f, 1.825378f, 10.0f,
	-17.803158f, -0.031738f, 10.0f, -17.231750f, 1.825378f, 10.0f, -22.519829f, 3.527771f, 10.0f,
	-22.519829f, 3.527771f, 10.0f, -22.019829f, 0.027771f, 10.0f, -17.803158f, -0.031738f, 10.0f,
	3.333333f, 13.0f, 5.666667f, -3.0f, 8.0f, 10.0f, 9.916689f, 8.0f, 10.0f,
	3.333333f, 13.0f, 5.666667f, -12.999998f, 13.0f, 5.666667f, -3.0f, 8.0f, 10.0f,
	-12.999998f, 13.0f, 5.666667f, -17.200012f, 8.0f, 10.0f, -3.0f, 8.0f, 10.0f,
	17.343269f, 1.986084f, 10.0f, 17.343262f, 1.986111f, 0.0f, 17.843262f, 0.039682f, 0.0f,
	17.343269f, 1.986084f, 10.0f, 17.843262f, 0.039682f, 0.0f, 17.843269f, 0.039673f, 10.0f,
	17.843269f, 0.039673f, 10.0f, 17.843262f, 0.039682f, 0.0f, 22.718262f, 0.048611f, 0.0f,
	17.843269f, 0.039673f, 10.0f, 22.718262f, 0.048611f, 0.0f, 22.718269f, 0.048584f, 10.0f,
	22.718269f, 0.048584f, 10.0f, 22.718262f, 0.048611f, 0.0f, 24.218262f, 1.486111f, 0.0f,
	22.718269f, 0.048584f, 10.0f, 24.218262f, 1.486111f, 0.0f, 24.218269f, 1.486084f, 10.0f,
	24.218269f, 1.486084f, 10.0f, 24.218262f, 1.486111f, 0.0f, 24.905762f, 3.361111f, 0.0f,
	24.218269f, 1.486084f, 10.0f, 24.905762f, 3.361111f, 0.0f, 24.905769f, 3.361084f, 10.0f,
	24.905769f, 3.361084f, 10.0f, 24.905762f, 3.361111f, 0.0f, 24.093262f, 5.111111f, 0.0f,
	24.905769f, 3.361084f, 10.0f, 24.093262f, 5.111111f, 0.0f, 24.093269f, 5.111084f, 10.0f,
	24.093269f, 5.111084f, 10.0f, 24.093262f, 5.111111f, 0.0f, 22.182549f, 6.468254f, 0.0f,
	24.093269f, 5.111084f, 10.0f, 22.182549f, 6.468254f, 0.0f, 22.182503f, 6.468262f, 10.0f,
	15.843271f, 3.611084f, 10.0f, 15.843264f, 3.611111f, 0.0f, 17.343262f, 1.986111f, 0.0f,
	15.843271f, 3.611084f, 10.0f, 17.343262f, 1.986111f, 0.0f, 17.343269f, 1.986084f, 10.0f,
	14.093266f, 3.923584f, 10.0f, 14.093258f, 3.923611f, 0.0f, 15.843264f, 3.611111f, 0.0f,
	14.093266f, 3.923584f, 10.0f, 15.843264f, 3.611111f, 0.0f, 15.843271f, 3.611084f, 10.0f,
	22.182503f, 6.468262f, 10.0f, 22.182549f, 6.468254f, 0.0f, 9.916668f, 8.0f, 0.0f,
	22.182503f, 6.468262f, 10.0f, 9.916668f, 8.0f, 0.0f, 9.916689f, 8.0f, 10.0f,
	12.155764f, 3.423584f, 10.0f, 12.155756f, 3.423611f, 0.0f, 14.093258f, 3.923611f, 0.0f,
	12.155764f, 3.423584f, 10.0f, 14.093258f, 3.923611f, 0.0f, 14.093266f, 3.923584f, 10.0f,
	10.843264f, 1.986084f, 10.0f, 10.843256f, 1.986111f, 0.0f, 12.155756f, 3.423611f, 0.0f,
	10.843264f, 1.986084f, 10.0f, 12.155756f, 3.423611f, 0.0f, 12.155764f, 3.423584f, 10.0f,
	10.280764f, 0.048584f, 10.0f, 10.280756f, 0.048611f, 0.0f, 10.843256f, 1.986111f, 0.0f,
	10.280764f, 0.048584f, 10.0f, 10.843256f, 1.986111f, 0.0f, 10.843264f, 1.986084f, 10.0f,
	-10.200012f, 0.0f, 10.0f, -10.200001f, 0.0f, 0.0f, 10.280756f, 0.048611f, 0.0f,
	-10.200012f, 0.0f, 10.0f, 10.280756f, 0.048611f, 0.0f, 10.280764f, 0.048584f, 10.0f,
	-10.803162f, 1.825378f, 10.0f, -10.803175f, 1.825397f, 0.0f, -10.200001f, 0.0f, 0.0f,
	-10.803162f, 1.825378f, 10.0f, -10.200001f, 0.0f, 0.0f, -10.200012f, 0.0f, 10.0f,
	-12.088865f, 3.253967f, 10.0f, -12.088888f, 3.253968f, 0.0f, -10.803175f, 1.825397f, 0.0f,
	-12.088865f, 3.253967f, 10.0f, -10.803175f, 1.825397f, 0.0f, -10.803162f, 1.825378f, 10.0f,
	-14.088865f, 3.825378f, 10.0f, -14.088888f, 3.825397f, 0.0f, -12.088888f, 3.253968f, 0.0f,
	-14.088865f, 3.825378f, 10.0f, -12.088888f, 3.253968f, 0.0f, -12.088865f, 3.253967f, 10.0f,
	-15.969849f, 3.373038f, 10.0f, -15.969841f, 3.373016f, 0.0f, -14.088888f, 3.825397f, 0.0f,
	-15.969849f, 3.373038f, 10.0f, -14.088888f, 3.825397f, 0.0f, -14.088865f, 3.825378f, 10.0f,
	-17.231750f, 1.825378f, 10.0f, -17.231739f, 1.825397f, 0.0f, -15.969841f, 3.373016f, 0.0f,
	-17.231750f, 1.825378f, 10.0f, -15.969841f, 3.373016f, 0.0f, -15.969849f, 3.373038f, 10.0f,
	-17.200012f, 8.0f, 10.0f, -17.199993f, 8.0f, 0.0f, -20.519836f, 7.527778f, 0.0f,
	-17.200012f, 8.0f, 10.0f, -20.519836f, 7.527778f, 0.0f, -20.519833f, 7.527771f, 10.0f,
	-20.519833f, 7.527771f, 10.0f, -20.519836f, 7.527778f, 0.0f, -22.519836f, 3.527777f, 0.0f,
	-20.519833f, 7.527771f, 10.0f, -22.519836f, 3.527777f, 0.0f, -22.519829f, 3.527771f, 10.0f,
	-17.803158f, -0.031738f, 10.0f, -17.803162f, -0.031746f, 0.0f, -17.231739f, 1.825397f, 0.0f,
	-17.803158f, -0.031738f, 10.0f, -17.231739f, 1.825397f, 0.0f, -17.231750f, 1.825378f, 10.0f,
	-22.519829f, 3.527771f, 10.0f, -22.519836f, 3.527777f, 0.0f, -22.019836f, 0.027778f, 0.0f,
	-22.519829f, 3.527771f, 10.0f, -22.019836f, 0.027778f, 0.0f, -22.019829f, 0.027771f, 10.0f,
	-22.019829f, 0.027771f, 10.0f, -22.019836f, 0.027778f, 0.0f, -17.803162f, -0.031746f, 0.0f,
	-22.019829f, 0.027771f, 10.0f, -17.803162f, -0.031746f, 0.0f, -17.803158f, -0.031738f, 10.0f,
	9.916689f, 8.0f, 10.0f, 9.916668f, 8.0f, 0.0f, 3.333333f, 13.0f, 0.0f,
	9.916689f, 8.0f, 10.0f, 3.333333f, 13.0f, 0.0f, 3.333333f, 13.0f, 5.666667f,
	3.333333f, 13.0f, 5.666667f, 3.333333f, 13.0f, 0.0f, -12.999998f, 13.0f, 0.0f,
	3.333333f, 13.0f, 5.666667f, -12.999998f, 13.0f, 0.0f, -12.999998f, 13.0f, 5.666667f,
	-12.999998f, 13.0f, 5.666667f, -12.999998f, 13.0f, 0.0f, -17.199993f, 8.0f, 0.0f,
	-12.999998f, 13.0f, 5.666667f, -17.199993f, 8.0f, 0.0f, -17.200012f, 8.0f, 10.0f,
	22.718269f, 0.048584f, -10.0f, 17.843269f, 0.039673f, -10.0f, 17.343269f, 1.986084f, -10.0f,
	24.218269f, 1.486084f, -10.0f, 22.718269f, 0.048584f, -10.0f, 17.343269f, 1.986084f, -10.0f,
	24.905769f, 3.361084f, -10.0f, 24.218269f, 1.486084f, -10.0f, 17.343269f, 1.986084f, -10.0f,
	24.093269f, 5.111084f, -10.0f, 24.905769f, 3.361084f, -10.0f, 17.343269f, 1.986084f, -10.0f,
	22.182503f, 6.468262f, -10.0f, 24.093269f, 5.111084f, -10.0f, 17.343269f, 1.986084f, -10.0f,
	22.182503f, 6.468262f, -10.0f, 17.343269f, 1.986084f, -10.0f, 15.843271f, 3.611084f, -10.0f,
	22.182503f, 6.468262f, -10.0f, 15.843271f, 3.611084f, -10.0f, 14.093266f, 3.923584f, -10.0f,
	9.916689f, 8.0f, -10.0f, 22.182503f, 6.468262f, -10.0f, 14.093266f, 3.923584f, -10.0f,
	9.916689f, 8.0f, -10.0f, 14.093266f, 3.923584f, -10.0f, 12.155764f, 3.423584f, -10.0f,
	9.916689f, 8.0f, -10.0f, 12.155764f, 3.423584f, -10.0f, 10.843264f, 1.986084f, -10.0f,
	9.916689f, 8.0f, -10.0f, 10.843264f, 1.986084f, -10.0f, 10.280764f, 0.048584f, -10.0f,
	-10.200012f, 0.0f, -10.0f, 9.916689f, 8.0f, -10.0f, 10.280764f, 0.048584f, -10.0f,
	-10.200012f, 0.0f, -10.0f, -10.803162f, 1.825378f, -10.0f, 9.916689f, 8.0f, -10.0f,
	-10.803162f, 1.825378f, -10.0f, -12.088865f, 3.253967f, -10.0f, 9.916689f, 8.0f, -10.0f,
	9.916689f, 8.0f, -10.0f, -12.088865f, 3.253967f, -10.0f, -3.0f, 8.0f, -10.0f,
	-3.0f, 8.0f, -10.0f, -12.088865f, 3.253967f, -10.0f, -14.088865f, 3.825378f, -10.0f,
	-17.200012f, 8.0f, -10.0f, -3.0f, 8.0f, -10.0f, -14.088865f, 3.825378f, -10.0f,
	-17.200012f, 8.0f, -10.0f, -14.088865f, 3.825378f, -10.0f, -15.969849f, 3.373038f, -10.0f,
	-17.200012f, 8.0f, -10.0f, -15.969849f, 3.373038f, -10.0f, -17.231750f, 1.825378f, -10.0f,
	-20.519833f, 7.527771f, -10.0f, -17.200012f, 8.0f, -10.0f, -17.231750f, 1.825378f, -10.0f,
	-17.231750f, 1.825378f, -10.0f, -22.519829f, 3.527771f, -10.0f, -20.519833f, 7.527771f, -10.0f,
	-22.519829f, 3.527771f, -10.0f, -17.231750f, 1.825378f, -10.0f, -17.803158f, -0.031738f, -10.0f,
	-17.803158f, -0.031738f, -10.0f, -22.019829f, 0.027771f, -10.0f, -22.519829f, 3.527771f, -10.0f,
	9.916689f, 8.0f, -10.0f, -3.0f, 8.0f, -10.0f, 3.333333f, 13.0f, -5.666667f,
	-3.0f, 8.0f, -10.0f, -12.999998f, 13.0f, -5.666667f, 3.333333f, 13.0f, -5.666667f,
	-3.0f, 8.0f, -10.0f, -17.200012f, 8.0f, -10.0f, -12.999998f, 13.0f, -5.666667f,
	17.843262f, 0.039682f, 0.0f, 17.343262f, 1.986111f, 0.0f, 17.343269f, 1.986084f, -10.0f,
	17.843269f, 0.039673f, -10.0f, 17.843262f, 0.039682f, 0.0f, 17.343269f, 1.986084f, -10.0f,
	22.718262f, 0.048611f, 0.0f, 17.843262f, 0.039682f, 0.0f, 17.843269f, 0.039673f, -10.0f,
	22.718269f, 0.048584f, -10.0f, 22.718262f, 0.048611f, 0.0f, 17.843269f, 0.039673f, -10.0f,
	24.218262f, 1.486111f, 0.0f, 22.718262f, 0.048611f, 0.0f, 22.718269f, 0.048584f, -10.0f,
	24.218269f, 1.486084f, -10.0f, 24.218262f, 1.486111f, 0.0f, 22.718269f, 0.048584f, -10.0f,
	24.905762f, 3.361111f, 0.0f, 24.218262f, 1.486111f, 0.0f, 24.218269f, 1.486084f, -10.0f,
	24.905769f, 3.361084f, -10.0f, 24.905762f, 3.361111f, 0.0f, 24.218269f, 1.486084f, -10.0f,
	24.093262f, 5.111111f, 0.0f, 24.905762f, 3.361111f, 0.0f, 24.905769f, 3.361084f, -10.0f,
	24.093269f, 5.111084f, -10.0f, 24.093262f, 5.111111f, 0.0f, 24.905769f, 3.361084f, -10.0f,
	22.182549f, 6.468254f, 0.0f, 24.093262f, 5.111111f, 0.0f, 24.093269f, 5.111084f, -10.0f,
	22.182503f, 6.468262f, -10.0f, 22.182549f, 6.468254f, 0.0f, 24.093269f, 5.111084f, -10.0f,
	17.343262f, 1.986111f, 0.0f, 15.843264f, 3.611111f, 0.0f, 15.843271f, 3.611084f, -10.0f,
	17.343269f, 1.986084f, -10.0f, 17.343262f, 1.986111f, 0.0f, 15.843271f, 3.611084f, -10.0f,
	15.843264f, 3.611111f, 0.0f, 14.093258f, 3.923611f, 0.0f, 14.093266f, 3.923584f, -10.0f,
	15.843271f, 3.611084f, -10.0f, 15.843264f, 3.611111f, 0.0f, 14.093266f, 3.923584f, -10.0f,
	9.916668f, 8.0f, 0.0f, 22.182549f, 6.468254f, 0.0f, 22.182503f, 6.468262f, -10.0f,
	9.916689f, 8.0f, -10.0f, 9.916668f, 8.0f, 0.0f, 22.182503f, 6.468262f, -10.0f,
	14.093258f, 3.923611f, 0.0f, 12.155756f, 3.423611f, 0.0f, 12.155764f, 3.423584f, -10.0f,
	14.093266f, 3.923584f, -10.0f, 14.093258f, 3.923611f, 0.0f, 12.155764f, 3.423584f, -10.0f,
	12.155756f, 3.423611f, 0.0f, 10.843256f, 1.986111f, 0.0f, 10.843264f, 1.986084f, -10.0f,
	12.155764f, 3.423584f, -10.0f, 12.155756f, 3.423611f, 0.0f, 10.843264f, 1.986084f, -10.0f,
	10.843256f, 1.986111f, 0.0f, 10.280756f, 0.048611f, 0.0f, 10.280764f, 0.048584f, -10.0f,
	10.843264f, 1.986084f, -10.0f, 10.843256f, 1.986111f, 0.0f, 10.280764f, 0.048584f, -10.0f,
	10.280756f, 0.048611f, 0.0f, -10.200001f, 0.0f, 0.0f, -10.200012f, 0.0f, -10.0f,
	10.280764f, 0.048584f, -10.0f, 10.280756f, 0.048611f, 0.0f, -10.200012f, 0.0f, -10.0f,
	-10.200001f, 0.0f, 0.0f, -10.803175f, 1.825397f, 0.0f, -10.803162f, 1.825378f, -10.0f,
	-10.200012f, 0.0f, -10.0f, -10.200001f, 0.0f, 0.0f, -10.803162f, 1.825378f, -10.0f,
	-10.803175f, 1.825397f, 0.0f, -12.088888f, 3.253968f, 0.0f, -12.088865f, 3.253967f, -10.0f,
	-10.803162f, 1.825378f, -10.0f, -10.803175f, 1.825397f, 0.0f, -12.088865f, 3.253967f, -10.0f,
	-12.088888f, 3.253968f, 0.0f, -14.088888f, 3.825397f, 0.0f, -14.088865f, 3.825378f, -10.0f,
	-12.088865f, 3.253967f, -10.0f, -12.088888f, 3.253968f, 0.0f, -14.088865f, 3.825378f, -10.0f,
	-14.088888f, 3.825397f, 0.0f, -15.969841f, 3.373016f, 0.0f, -15.969849f, 3.373038f, -10.0f,
	-14.088865f, 3.825378f, -10.0f, -14.088888f, 3.825397f, 0.0f, -15.969849f, 3.373038f, -10.0f,
	-15.969841f, 3.373016f, 0.0f, -17.231739f, 1.825397f, 0.0f, -17.231750f, 1.825378f, -10.0f,
	-15.969849f, 3.373038f, -10.0f, -15.969841f, 3.373016f, 0.0f, -17.231750f, 1.825378f, -10.0f,
	-20.519836f, 7.527778f, 0.0f, -17.199993f, 8.0f, 0.0f, -17.200012f, 8.0f, -10.0f,
	-20.519833f, 7.527771f, -10.0f, -20.519836f, 7.527778f, 0.0f, -17.200012f, 8.0f, -10.0f,
	-22.519836f, 3.527777f, 0.0f, -20.519836f, 7.527778f, 0.0f, -20.519833f, 7.527771f, -10.0f,
	-22.519829f, 3.527771f, -10.0f, -22.519836f, 3.527777f, 0.0f, -20.519833f, 7.527771f, -10.0f,
	-17.231739f, 1.825397f, 0.0f, -17.803162f, -0.031746f, 0.0f, -17.803158f, -0.031738f, -10.0f,
	-17.231750f, 1.825378f, -10.0f, -17.231739f, 1.825397f, 0.0f, -17.803158f, -0.031738f, -10.0f,
	-22.019836f, 0.027778f, 0.0f, -22.519836f, 3.527777f, 0.0f, -22.519829f, 3.527771f, -10.0f,
	-22.019829f, 0.027771f, -10.0f, -22.019836f, 0.027778f, 0.0f, -22.519829f, 3.527771f, -10.0f,
	-17.803162f, -0.031746f, 0.0f, -22.019836f, 0.027778f, 0.0f, -22.019829f, 0.027771f, -10.0f,
	-17.803158f, -0.031738f, -10.0f, -17.803162f, -0.031746f, 0.0f, -22.019829f, 0.027771f, -10.0f,
	3.333333f, 13.0f, 0.0f, 9.916668f, 8.0f, 0.0f, 9.916689f, 8.0f, -10.0f,
	3.333333f, 13.0f, -5.666667f, 3.333333f, 13.0f, 0.0f, 9.916689f, 8.0f, -10.0f,
	-12.999998f, 13.0f, 0.0f, 3.333333f, 13.0f, 0.0f, 3.333333f, 13.0f, -5.666667f,
	-12.999998f, 13.0f, -5.666667f, -12.999998f, 13.0f, 0.0f, 3.333333f, 13.0f, -5.666667f,
	-17.199993f, 8.0f, 0.0f, -12.999998f, 13.0f, 0.0f, -12.999998f, 13.0f, -5.666667f,
	-17.200012f, 8.0f, -10.0f, -17.199993f, 8.0f, 0.0f, -12.999998f, 13.0f, -5.666667f,
	-22.254627f, 1.511728f, 7.5f, -22.151180f, 1.161731f, 8.106218f, -22.116699f, 0.846211f, 7.5f,
	-24.337391f, 1.511728f, 7.5f, -24.337391f, 0.811729f, 7.5f, -24.337391f, 1.161731f, 8.106218f,
	-22.254627f, 1.511728f, 7.5f, -24.337391f, 1.511728f, 7.5f, -22.151180f, 1.161731f, 8.106218f,
	-24.337391f, 1.511728f, 7.5f, -24.337391f, 1.161731f, 8.106218f, -22.151180f, 1.161731f, 8.106218f,
	-22.151180f, 1.161731f, 8.106218f, -22.047729f, 0.461727f, 8.106218f, -22.116699f, 0.846211f, 7.5f,
	-24.337391f, 1.161731f, 8.106218f, -24.337391f, 0.811729f, 7.5f, -24.337391f, 0.461726f, 8.106218f,
	-22.151180f, 1.161731f, 8.106218f, -24.337391f, 1.161731f, 8.106218f, -24.337391f, 0.461726f, 8.106218f,
	-22.151180f, 1.161731f, 8.106218f, -24.337391f, 0.461726f, 8.106218f, -22.047729f, 0.461727f, 8.106218f,
	-22.047729f, 0.461727f, 8.106218f, -22.013248f, 0.111728f, 7.5f, -22.116699f, 0.846211f, 7.5f,
	-24.337391f, 0.461726f, 8.106218f, -24.337391f, 0.811729f, 7.5f, -24.337391f, 0.111732f, 7.5f,
	-22.047729f, 0.461727f, 8.106218f, -24.337391f, 0.461726f, 8.106218f, -22.013248f, 0.111728f, 7.5f,
	-24.337391f, 0.461726f, 8.106218f, -24.337391f, 0.111732f, 7.5f, -22.013248f, 0.111728f, 7.5f,
	-22.013248f, 0.111728f, 7.5f, -22.047729f, 0.461727f, 6.893783f, -22.116699f, 0.846211f, 7.5f,
	-24.337391f, 0.111732f, 7.5f, -24.337391f, 0.811729f, 7.5f, -24.337391f, 0.461726f, 6.893783f,
	-22.013248f, 0.111728f, 7.5f, -24.337391f, 0.111732f, 7.5f, -24.337391f, 0.461726f, 6.893783f,
	-22.013248f, 0.111728f, 7.5f, -24.337391f, 0.461726f, 6.893783f, -22.047729f, 0.461727f, 6.893783f,
	-22.047729f, 0.461727f, 6.893783f, -22.151180f, 1.161731f, 6.893783f, -22.116699f, 0.846211f, 7.5f,
	-24.337391f, 0.461726f, 6.893783f, -24.337391f, 0.811729f, 7.5f, -24.337391f, 1.161731f, 6.893783f,
	-22.047729f, 0.461727f, 6.893783f, -24.337391f, 0.461726f, 6.893783f, -22.151180f, 1.161731f, 6.893783f,
	-24.337391f, 0.461726f, 6.893783f, -24.337391f, 1.161731f, 6.893783f, -22.151180f, 1.161731f, 6.893783f,
	-22.151180f, 1.161731f, 6.893783f, -22.254627f, 1.511728f, 7.5f, -22.116699f, 0.846211f, 7.5f,
	-24.337391f, 1.161731f, 6.893783f, -24.337391f, 0.811729f, 7.5f, -24.337391f, 1.511728f, 7.5f,
	-22.151180f, 1.161731f, 6.893783f, -24.337391f, 1.161731f, 6.893783f, -24.337391f, 1.511728f, 7.5f,
	-22.151180f, 1.161731f, 6.893783f, -24.337391f, 1.511728f, 7.5f, -22.254627f, 1.511728f, 7.5f };

#endif
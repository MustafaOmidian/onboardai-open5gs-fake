/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER`
 */

#include "NGAP_ServiceType.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_NGAP_ServiceType_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_NGAP_ServiceType_value2enum_1[] = {
	{ 0,	9,	"streaming" },
	{ 1,	4,	"mTSI" },
	{ 2,	2,	"vR" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NGAP_ServiceType_enum2value_1[] = {
	1,	/* mTSI(1) */
	0,	/* streaming(0) */
	2	/* vR(2) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_NGAP_ServiceType_specs_1 = {
	asn_MAP_NGAP_ServiceType_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_NGAP_ServiceType_enum2value_1,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NGAP_ServiceType_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_NGAP_ServiceType = {
	"ServiceType",
	"ServiceType",
	&asn_OP_NativeEnumerated,
	asn_DEF_NGAP_ServiceType_tags_1,
	sizeof(asn_DEF_NGAP_ServiceType_tags_1)
		/sizeof(asn_DEF_NGAP_ServiceType_tags_1[0]), /* 1 */
	asn_DEF_NGAP_ServiceType_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_ServiceType_tags_1)
		/sizeof(asn_DEF_NGAP_ServiceType_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NGAP_ServiceType_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NGAP_ServiceType_specs_1	/* Additional specs */
};


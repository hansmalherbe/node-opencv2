{
	'variables' : {
		'opencv_dir': 'c:/opencv242/build/',
		'boost_dir': 'c:/boost_1_49_0',
		'conf': '$(ConfigurationName)',
	},
	'conditions': [
		['OS=="win"', {
			'conditions': [
				['target_arch=="x64"', {
					'variables': {
						'opencv_libs': '<(opencv_dir)x64/vc10/',
						'opencv_tbb': '<(opencv_dir)common/tbb/intel64/vc10/',
					},
				},{
					'variables': {
						'opencv_libs': '<(opencv_dir)x86/vc10/',
						'opencv_tbb': '<(opencv_dir)common/tbb/ia32/vc10/',
					},
				}],
			],
		}],
	],
	'targets': [
		{
			'target_name': 'opencv2',
			'sources': [ 
				'./src/opencv2.cc',
				'./src/help.cc',
				'./src/mat.cc',
				'./src/object_proxy.cc',
			],
			'msbuild_props': [
				'node.vsprops'
			],
			'include_dirs': [ './src', '<(opencv_dir)include', '<(boost_dir)' ],
			'link_settings': {
				'libraries': [
					'<(opencv_libs)lib/opencv_calib3d242.lib',
					'<(opencv_libs)lib/opencv_contrib242.lib',
					'<(opencv_libs)lib/opencv_core242.lib',
					'<(opencv_libs)lib/opencv_features2d242.lib',
					'<(opencv_libs)lib/opencv_flann242.lib',
					'<(opencv_libs)lib/opencv_gpu242.lib',
					'<(opencv_libs)lib/opencv_haartraining_engine.lib',
					'<(opencv_libs)lib/opencv_highgui242.lib',
					'<(opencv_libs)lib/opencv_imgproc242.lib',
					'<(opencv_libs)lib/opencv_legacy242.lib',
					'<(opencv_libs)lib/opencv_ml242.lib',
					'<(opencv_libs)lib/opencv_nonfree242.lib',
					'<(opencv_libs)lib/opencv_objdetect242.lib',
					'<(opencv_libs)lib/opencv_photo242.lib',
					'<(opencv_libs)lib/opencv_stitching242.lib',
					'<(opencv_libs)lib/opencv_ts242.lib',
					'<(opencv_libs)lib/opencv_video242.lib',
					'<(opencv_libs)lib/opencv_videostab242.lib',
				],
				'conditions': [
					['OS=="win"', {
						'libraries/': [
							['exclude', '\\.a$'],
						],
					}],
				],
			},
			'conditions': [
				['OS=="win"', {
					'msvs_guid': 'FC93254D-884A-4FE7-B74F-2301D842BB78',
					#'msvs_disabled_warnings': [4351, 4355, 4800],
					'copies': [
						{
							'destination': './build/$(ConfigurationName)/',
							'files': [
								'<(opencv_tbb)tbb.dll',
								'<(opencv_tbb)tbb_preview.dll',
								'<(opencv_tbb)tbbmalloc.dll',
								'<(opencv_tbb)tbbmalloc_proxy.dll',

								'<(opencv_libs)bin/opencv_calib3d242.dll',
								'<(opencv_libs)bin/opencv_contrib242.dll',
								'<(opencv_libs)bin/opencv_core242.dll',
								'<(opencv_libs)bin/opencv_features2d242.dll',
								'<(opencv_libs)bin/opencv_flann242.dll',
								'<(opencv_libs)bin/opencv_gpu242.dll',
								'<(opencv_libs)bin/opencv_highgui242.dll',
								'<(opencv_libs)bin/opencv_imgproc242.dll',
								'<(opencv_libs)bin/opencv_legacy242.dll',
								'<(opencv_libs)bin/opencv_ml242.dll',
								'<(opencv_libs)bin/opencv_nonfree242.dll',
								'<(opencv_libs)bin/opencv_objdetect242.dll',
								'<(opencv_libs)bin/opencv_photo242.dll',
								'<(opencv_libs)bin/opencv_stitching242.dll',
								'<(opencv_libs)bin/opencv_ts242.dll',
								'<(opencv_libs)bin/opencv_video242.dll',
								'<(opencv_libs)bin/opencv_videostab242.dll',

							],
							'conditions': [
								['target_arch=="x64"', {
									'files': [
										'<(opencv_libs)bin/opencv_ffmpeg242_64.dll',
									],
								}, {
									'files': [
										'<(opencv_libs)bin/opencv_ffmpeg242.dll',
									],
								}]
							],
						},
					],
					'configurations': {
						'Debug': {
							'msvs_settings': {
								'VCLinkerTool': {
						            'AdditionalDependencies': [
						            	'vfw32.lib', 
						            	'comctl32.lib', 
						            	'<(opencv_libs)staticlib/zlib.lib', 
						            	'<(opencv_libs)staticlib/libtiff.lib',
						            	'<(opencv_libs)staticlib/libpng.lib',
						            	'<(opencv_libs)staticlib/libjpeg.lib',
						            	'<(opencv_libs)staticlib/libjasper.lib'
						            ],
								},
							},
						},
						'Release': {
							'msvs_settings': {
								'VCCLCompilerTool': {
									'ExceptionHandling': '2',  # /EHsc
								},
								'VCLinkerTool': {
						            'AdditionalDependencies': [
						            	'vfw32.lib', 
						            	'comctl32.lib', 
						            	'<(opencv_libs)staticlib/zlib.lib', 
						            	'<(opencv_libs)staticlib/libtiff.lib',
						            	'<(opencv_libs)staticlib/libpng.lib',
						            	'<(opencv_libs)staticlib/libjpeg.lib',
						            	'<(opencv_libs)staticlib/libjasper.lib'
						            ],
									# LinkIncremental values:
									#   0 == default
									#   1 == /INCREMENTAL:NO
									#   2 == /INCREMENTAL
									#'LinkIncremental': '1',
								},
							},
						},
					},
					'defines': [
						'WINDOWS_SUPPRESS_WARNINGS',
					],
					'include_dirs': [],
				}]
			]
		}
	]
}
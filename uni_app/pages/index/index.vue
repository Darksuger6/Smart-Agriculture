<template>
	<view class="wrapper">
		<view class="device-area">
			<view class="device-cart">
				<view class="device-info">
					<view class="device-name">温度</view>
					<image class="device-logo" src="/static//Temp.png"></image>	
				</view>	
				<view class="device-data">{{Temp}}℃</view>	
			</view>
			
			<view class="device-cart">
				<view class="device-info">
					<view class="device-name">湿度</view>
					<image class="device-logo" src="/static//Humi.png"></image>	
				</view>	
				<view class="device-data">{{Humi}}%</view>	
			</view>
			
			<view class="device-cart">
				<view class="device-info">
					<view class="device-name">光照强度</view>
					<image class="device-logo" src="/static//Light.png"></image>	
				</view>	
				<view class="device-data">{{Light}}%</view>
			</view>
			
			<view class="device-cart">
				<view class="device-info">
					<view class="device-name">土壤湿度</view>
					<image class="device-logo" src="/static//Soil.png"></image>	
				</view>	
				<view class="device-data">{{Soil}}%</view>
			</view>
			
			<view class="device-cart">
				<view class="device-info">
					<view class="device-name">补光</view>
					<image class="device-logo" src="/static///JdqBG.png"></image>	
				</view>
				<switch @change="onLightSwitch" color="#1296db" :checked="Lightkey"/>
			</view>
			
			<view class="device-cart">
				<view class="device-info">
					<view class="device-name">补水</view>
					<image class="device-logo" src="/static///JdqBS.png"></image>	
				</view>
				<switch @change="onSoilSwitch" color="#1296db" :checked="Soilkey"/>
			</view>
			
			<view class="device-cart">
				<view class="device-info">
					<view class="device-name">自动控制</view>
					<image class="device-logo" src="/static////Auto.png"></image>	
				</view>
				<switch @change="onAutoSwitch" color="#1296db" :checked="Autoflag"/>
			</view>
		</view>
		<!-- <image class="logo" src="/static/logo.png"></image>
		<view class="text-area">
			<text class="title">{{title}}</text>
		</view> -->
	</view>
</template>

<script>
	import {
		stringify
	} from 'querystring';
	
	export default {
		data() {
			return {
				Temp: 0,
				Humi: 0,
				Light: 0,
				Soil: 0,
				Lightkey: false,
				Soilkey: false,
				Autoflag: false,
				Soilvalue: 70,
				Lightvalue: 28,
			}
		},
		
		onShow() {
			//this.GetDatapoints()
			/* let that = this
			this.GetDatapoints()
			setInterval(function(){
				that.GetDatapoints()
				},3000); */
				this.timer = setInterval(() => {
				    //TODO 
					this.GetDatapoints()
				}, 1000); 
		},
		
		onLoad() {
		/* uni.request({
		    url: 'http://api.heclouds.com/devices/1058321713/datapoints?', //仅为示例，并非真实接口地址。
		    
		    header: {
		       'api-key': '98=J8pzdhMN4W2SmGLc0B9Y3JWw=' //自定义请求头信息
		    },
			method:'GET',
		    success: (res) => {
		        console.log(res.data);
				console.log(res.data.data.datastreams[4].id,res.data.data.datastreams[4].datapoints[0].value);
		        console.log(res.data.data.datastreams[2].id,res.data.data.datastreams[2].datapoints[0].value);
				console.log(res.data.data.datastreams[3].id,res.data.data.datastreams[3].datapoints[0].value);
				console.log(res.data.data.datastreams[1].id,res.data.data.datastreams[1].datapoints[0].value);
				this.Temp=res.data.data.datastreams[4].datapoints[0].value;
				this.Humi=res.data.data.datastreams[2].datapoints[0].value;
				this.Light=res.data.data.datastreams[3].datapoints[0].value;
				this.Soil=res.data.data.datastreams[1].datapoints[0].value;
		    }
		}); */

		},
		methods: {
			GetDatapoints: function(){
				uni.request({
				    url: 'http://api.heclouds.com/devices/1205733705/datapoints?', //仅为示例，并非真实接口地址。
				    
				    header: {
				       'api-key': '1fo4t6xEdHImsyfE9y9RNHSBoBc=' //自定义请求头信息
				    },
					method:'GET',
				    success: (res) => {
				        console.log(res.data);
						console.log(res.data.data.datastreams[7].id,res.data.data.datastreams[7].datapoints[0].value);//温度
				        console.log(res.data.data.datastreams[3].id,res.data.data.datastreams[3].datapoints[0].value);//湿度
						console.log(res.data.data.datastreams[2].id,res.data.data.datastreams[2].datapoints[0].value);//光照强度
						console.log(res.data.data.datastreams[4].id,res.data.data.datastreams[4].datapoints[0].value);//土壤湿度
						console.log(res.data.data.datastreams[0].id,res.data.data.datastreams[0].datapoints[0].value);//补光开关
						console.log(res.data.data.datastreams[6].id,res.data.data.datastreams[6].datapoints[0].value);//补水开关
						console.log(res.data.data.datastreams[5].id,res.data.data.datastreams[5].datapoints[0].value);//自动控制
						console.log(res.data.data.datastreams[1].id,res.data.data.datastreams[1].datapoints[0].value);//Lightvalue
						console.log(res.data.data.datastreams[8].id,res.data.data.datastreams[8].datapoints[0].value);//Soilvalue
						
						this.Temp=res.data.data.datastreams[7].datapoints[0].value;
						this.Humi=res.data.data.datastreams[3].datapoints[0].value;
						this.Light=res.data.data.datastreams[2].datapoints[0].value;
						this.Soil=res.data.data.datastreams[4].datapoints[0].value;
						this.Lightkey=res.data.data.datastreams[0].datapoints[0].value === 'true';
						this.Soilkey=res.data.data.datastreams[6].datapoints[0].value === 'true';
						this.Autoflag=res.data.data.datastreams[5].datapoints[0].value === 'true';
						this.Lightvalue=res.data.data.datastreams[1].datapoints[0].value;
						this.Soilvalue=res.data.data.datastreams[8].datapoints[0].value;
				    }
				});
			},
			onLightSwitch(event){
				console.log(event.detail.value);
				let sw = event.detail.value;
				if(sw) {
					uni.request({
					    url: 'http://api.heclouds.com/mqtt?topic=Agricultural', //仅为示例，并非真实接口地址。
					    
					    header: {
					       'api-key': '43hWznSpmZJSP1bRs0GTFvevTsE=' //Master-key
					    },
						method:'POST',
						data:{"LED":1},
					    success: (res) => {
					        console.log("LED on!");
					    }
					});
				}
				else{
					uni.request({
					    url: 'http://api.heclouds.com/mqtt?topic=Agricultural', //仅为示例，并非真实接口地址。
					    
					    header: {
					       'api-key': '43hWznSpmZJSP1bRs0GTFvevTsE=' //Master-key
					    },
						method:'POST',
						data:{"LED":0},
					    success: (res) => {
					        console.log("LED off!");
					    }
					});
				}
			},
			onSoilSwitch(event){
				console.log(event.detail.value);
				let sw = event.detail.value;
				if(sw) {
					uni.request({
					    url: 'http://api.heclouds.com/mqtt?topic=Agricultural', //仅为示例，并非真实接口地址。
					    
					    header: {
					       'api-key': '43hWznSpmZJSP1bRs0GTFvevTsE=' //Master-key
					    },
						method:'POST',
						data:{"Water":1},
					    success: (res) => {
					        console.log("Water on!");
					    }
					});
				}
				else{
					uni.request({
					    url: 'http://api.heclouds.com/mqtt?topic=Agricultural', //仅为示例，并非真实接口地址。
					    
					    header: {
					       'api-key': '43hWznSpmZJSP1bRs0GTFvevTsE=' //Master-key
					    },
						method:'POST',
						data:{"Water":0},
					    success: (res) => {
					        console.log("Water off!");
					    }
					});
				}
			},
			onAutoSwitch(event){
				console.log(event.detail.value);
				let sw = event.detail.value;
				if(sw) {
					uni.request({
					    url: 'http://api.heclouds.com/mqtt?topic=Agricultural', //仅为示例，并非真实接口地址。
					    
					    header: {
					       'api-key': '43hWznSpmZJSP1bRs0GTFvevTsE=' //Master-key
					    },
						method:'POST',
						data:{"Auto":1},
					    success: (res) => {
					        console.log("Auto on!");
					    }
					});
				}
				else{
					uni.request({
					    url: 'http://api.heclouds.com/mqtt?topic=Agricultural', //仅为示例，并非真实接口地址。
					    
					    header: {
					       'api-key': '43hWznSpmZJSP1bRs0GTFvevTsE=' //Master-key
					    },
						method:'POST',
						data:{"Auto":0},
					    success: (res) => {
					        console.log("Auto off!");
					    }
					});
				}
			},
		}
	}
</script>

<style>
	.wrapper {
		display: flex;
		flex-direction: column;
		align-items: center;
		justify-content: center;
	}

	.device-area {
		display: flex;
		justify-content: space-around;
		flex-wrap: wrap;
	}

	.device-cart {
		width: 320rpx;
		height: 220rpx;
		border-radius: 20rpx;
		margin-top: 30rpx;
		display: flex;
		justify-content: space-around;
		align-items: center;
		/* background-color: #8f8f94; */
		box-shadow: 0 0 15rpx #ccc;
	}

	.device-info {
		/* width: 100rpx;
		height: 100rpx; */
		font-size: 40rpx;
		/* font-size: 36rpx; */
		/* background-color: #8f8f94; */
	}
	
	.device-name{
		text-align: center;
		color: #6d6d6d;
	}
	
	.device-logo{
		width: 100rpx;
		height: 100rpx;
		margin-top: 30rpx;
	}
	
	.device-data{
		font-size: 66rpx;
		color: #6d6d6d;
	}
	
</style>
